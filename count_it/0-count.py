#!/usr/bin/python3

"""
Module to count keywords in hot Reddit post titles recursively.
"""

import requests


def count_words(subreddit, word_list, after=None, counts=None):
    """
    Recursively count words in hot Reddit titles.
    """

    if counts is None:
        counts = {}

        # Initialize counts dictionary with lowercase words.
        for word in word_list:
            lw = word.lower()
            counts[lw] = counts.get(lw, 0) + 0

    url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    headers = {"User-Agent": "Python3:holberton:0.1 (by /u/fchavonet)"}
    params = {"limit": 100}

    if after:
        params["after"] = after

    try:
        response = requests.get(url, headers=headers,
                                params=params, allow_redirects=False)

        if response.status_code != 200:
            return

        data = response.json().get("data", {})
    except Exception:
        return

    children = data.get("children", [])

    for post in children:
        title = post["data"]["title"].lower().split()

        for word in counts.keys():
            counts[word] += title.count(word)

    after = data.get("after")

    if after:
        # Recursive call for the next page.
        return count_words(subreddit, word_list, after, counts)

    # Final print sorted by count descending, then alphabetically.
    sorted_counts = sorted(
        [(k, v) for k, v in counts.items() if v > 0],
        key=lambda x: (-x[1], x[0])
    )

    for word, count in sorted_counts:
        print(f"{word}: {count}")
