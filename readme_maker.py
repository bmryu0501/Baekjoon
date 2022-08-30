#%% imports
import os
from urllib.request import urlopen
from bs4 import BeautifulSoup
import numpy as np

#%% get problem number list
import os

file_list = os.listdir('./codes/')
problems = []
for i in range(len(file_list)):
    problems.append(file_list[i][:-4]) # slice '.cpp'

print(problems)

#%% problem number + title
from urllib.request import urlopen
from bs4 import BeautifulSoup

for i in range(len(problems)) :
    # get problem title
    url = 'https://www.acmicpc.net/problem/' + problems[i]
    html = urlopen(url)
    soup = BeautifulSoup(html, 'html.parser')
    problem_title = soup.find(id='problem_title').contents[0]

    # make in tuple (number, title)
    problems[i] = (problems[i], problem_title)

print(problems)

#%% Readme contents
f = open('README.md', 'w')

# Title
f.write('# Baekjoon\n\n')

# Abstract

# Problems
f.write('## Solved Problems\n')
for problem in problems:
    text = ('- [\\[' + problem[0] + '\\] ' + problem[1] + ']' +
            '(https://www.acmicpc.net/problem/' + problem[0] + ')' + '\n')
    f.write(text)

f.close()
# %%
