#!/usr/bin/python3
'''
create recursive fonction that queries the Reddit API,
parses the title of all hot articles,
and prints a sorted count of given keywords.
'''
from collections import Counter
import re
import requests


def count_words(subreddit, word_list, after=None, count={}):
    '''
    Recursive function to query the Reddit API,
    parse the title of all hot articles,
    and print a sorted count of given keywords.
    '''
    headers = {
        'User-Agent': 'your_user_agent'
    }

    if after is None:
        url = f'https://oauth.reddit.com/r/{subreddit}/hot/.json?limit=100'
    else:
        url = f'https://oauth.reddit.com/r/{subreddit}/hot/.json?limit=100&after={after}'

    response = requests.get(url, headers=headers)
    data = response.json()

    for post in data['data']['children']:
        title = post['data']['title'].lower()
        for word in word_list:
            word = word.lower()
            if re.search(r'\b' + re.escape(word) + r'\b', title):
                count[word] = count.get(word, 0) + title.count(word)

    if len(data['data']['children']) == 100:
        after = data['data']['after']
        count_words(subreddit, word_list, after, count)
    else:
        for word, freq in sorted(count.items(), key=lambda x: (-x[1], x[0])):
            if freq > 0:
                print(f"{word}: {freq}")
                
    return count
