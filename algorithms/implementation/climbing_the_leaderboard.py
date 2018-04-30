import os


def climbingLeaderboard(scores, alice):
    scores = sorted(list(set(scores)))
    results = []

    i = 0

    for a in alice:
        try:
            while True:
                if i < len(scores) and a >= scores[i]:
                    i += 1
                else:
                    results.append(len(scores) + 1 - i)
                    break
        except:
            results.append(1)

    return results


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    scores_count = int(input())
    scores = list(map(int, input().rstrip().split()))
    alice_count = int(input())
    alice = list(map(int, input().rstrip().split()))
    result = climbingLeaderboard(scores, alice)
    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')
    fptr.close()
