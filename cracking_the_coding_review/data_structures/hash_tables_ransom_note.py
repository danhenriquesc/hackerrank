from collections import Counter


def ransom_note(magazine, ransom):
    c_m = Counter(magazine)
    c_r = Counter(ransom)

    for word in c_r.keys():
        if c_r.get(word, 0) > c_m.get(word, 0):
            return False

    return True


m, n = map(int, input().strip().split(' '))
magazine = input().strip().split(' ')
ransom = input().strip().split(' ')
answer = ransom_note(magazine, ransom)
if(answer):
    print("Yes")
else:
    print("No")
