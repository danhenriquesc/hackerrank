def solve(arr, money):
    htable = {}

    for i, value in enumerate(arr, 1):
        if value in htable:
            htable[value].append(i)
        else:
            htable[value] = [i]

    arr = sorted(arr)

    init = 0
    end = len(arr) - 1

    while init <= end:
        while arr[init] + arr[end] > money:
            end -= 1

        if arr[init] + arr[end] == money:
            s1, s2 = htable[arr[init]].pop(0), htable[arr[end]].pop()
            print(min(s1, s2), max(s1, s2))
            break

        init += 1
        end = len(arr) - 1


if __name__ == "__main__":
    t = int(input().strip())
    for a0 in range(t):
        money = int(input().strip())
        n = int(input().strip())
        arr = list(map(int, input().strip().split(' ')))
        solve(arr, money)
