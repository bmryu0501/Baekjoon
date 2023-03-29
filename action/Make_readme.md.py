'''
Make readme.md for solved problems
'''
#%% 
import os
import json

# get dictionary of problem id and title from json file
# with open('./solved.json', 'r') as f:
#     solved = json.load(f)

# tier
tier = ['Bronze', 'Silver', 'Gold', 'Platinum', 'Diamond', 'Ruby']

# get problem number list from file name
file_list = os.listdir('../solved/')
problem_ids = [file[:-4] for file in file_list if file.endswith('cpp')]