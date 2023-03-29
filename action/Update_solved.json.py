#%% prepare
import os

user_id = 'bmryu0501'

import http.client
conn = http.client.HTTPSConnection("solved.ac")
headers = { 'Content-Type': "application/json" }
request = "/api/v3/problem/show?problemId="

#%% get problem number list
# get problem number list from file name
file_list = os.listdir('../solved/')
problem_ids = [file[:-4] for file in file_list if file.endswith('cpp')]

# Load solved.json to write new problems
with open('solved.json', 'r') as f:
    solved = json.load(f)

#%% make json file for every problem
problems = []
import json
for problem_id in problem_ids:
    conn.request("GET", request + problem_id, headers=headers)
    res = conn.getresponse()
    data = res.read()
    data = data.decode("utf-8")
    data = json.loads(data)

    level = data['level']
    problem = {"id": data['problemId'], "title": data['titleKo'], "tags": [tags['bojTagId'] for tags in data['tags']]}

    for i in range(len(problems)):
        if problems[i]['level'] == level:
            problems[i]['size'] += 1
            problems[i]['problems'].append(problem)
            break
    else:
        problems.append({"level": level, "size": 0, "problems": [problem]})

#%% save problems to json file
with open('solved.json', 'w') as f:
    json.dump(problems, f)

#%% move problems into correct folder
tier = ['Bronze', 'Silver', 'Gold', 'Platinum', 'Diamond', 'Ruby']
for problem in problems:
    level = problem['level']
    for i in range(len(tier)):
        if level == tier[i]:
            level = i
            break
    else:
        level = 0
    os.rename(f'../solved/{problem["id"]}.cpp', f'../solved/{tier[(level-1)%5]}/{problem["id"]}.cpp')