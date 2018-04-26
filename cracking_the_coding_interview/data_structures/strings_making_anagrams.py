import string
from collections import Counter


def number_needed(a, b):
    letters = list(string.ascii_lowercase)

    a_freq = Counter(a.strip())
    b_freq = Counter(b.strip())

    count = 0
    for letter in letters:
        count += abs(a_freq.get(letter, 0) - b_freq.get(letter, 0))

    return count


a = input().strip()
b = input().strip()

print(number_needed(a, b))
