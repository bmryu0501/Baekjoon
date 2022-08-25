#%% imports
import os
from urllib.request import urlopen
from bs4 import BeautifulSoup
import numpy as np

#%% get problem number list
import os

file_list = os.listdir('./codes/')
problem_list = []
for i in range(len(file_list)):
    problem_list.append(file_list[i][:-4]) # slice '.cpp'

print(problem_list)

#%% problem title crawling
from urllib.request import urlopen
from bs4 import BeautifulSoup

url = 'https://www.acmicpc.net/problem/1000'

html = urlopen(url)
soup = BeautifulSoup(html, 'html.parser')

problem_title = soup.find(id='problem_title').contents
print(problem_title[0])

#%% make words to display
for i in range(len(file_list)):
    file_list[i] = ('- [' + problem_list[i] + ']' +
                    '(https://www.acmicpc.net/problem/' + problem_list[i] + ')'
                    )

print(file_list)