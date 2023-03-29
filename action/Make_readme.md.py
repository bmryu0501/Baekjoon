'''
Make readme.md for solved problems
using readme.md template and solved.json
'''
#%% 
import os
import json

# tier
tier = ['Bronze', 'Silver', 'Gold', 'Platinum', 'Diamond', 'Ruby']

#%%
# load solved.json
with open('solved.json', 'r') as f:
    solved = json.load(f)

#%%
# load readme.md template
with open('README.template.md', 'r') as f:
    readme = f.read()