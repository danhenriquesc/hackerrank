def lonely_integer(a):
    bits = [0 for _ in range(100)]

    for i in a:
        bits[i] ^= i

    return list(filter(lambda x: x, bits)).pop()


n = int(input().strip())
a = [int(a_temp) for a_temp in input().strip().split(' ')]
print(lonely_integer(a))
