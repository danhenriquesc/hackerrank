import os


def maximumProgramValue(n):
    total = 0

    for _ in range(n):
        cmd, val = input().split(' ')
        val = int(val)

        if cmd == 'add':
            if val > 0:
                total += val
        else:
            if val > total:
                total = val

    return total


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    n = int(input())
    result = maximumProgramValue(n)
    fptr.write(str(result) + '\n')
    fptr.close()
