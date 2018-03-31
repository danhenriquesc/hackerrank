T = input()

sells = {}
queries = []
states = {}


def feed_sell(d, p, s):
    key = "p{}".format(p)
    if not sells[d].get(key):
        sells[d][key] = {}

    key2 = "s{}".format(s)
    if not sells[d][key].get(key2):
        sells[d][key][key2] = 0

    sells[d][key][key2] += 1


def add_sell(d, p, s):
    if not sells.get(d):
        sells[d] = {}

    p1 = None
    s1 = None

    pp = p.split(".")
    if len(pp) == 1:
        p = "{}.0".format(p)
    else:
        p1 = "{}.0".format(pp[0])

    ss = s.split(".")
    if len(ss) == 1:
        s = "{}.0".format(s)
    else:
        s1 = "{}.0".format(ss[0])

    feed_sell(d, p, s)
    feed_sell(d, p, "-1.0")
    feed_sell(d, "-1.0", s)
    feed_sell(d, "-1.0", "-1.0")

    if p1 and s1:
        feed_sell(d, p1, s1)

    if p1:
        feed_sell(d, p1, s)
        feed_sell(d, p1, "-1.0")

    if s1:
        feed_sell(d, p, s1)
        feed_sell(d, "-1.0", s1)


line = 1
for l in range(int(T)):
    C, d, p, s = input().strip().split(" ")
    if C == "S":
        add_sell(d, p, s)
    elif C == "Q":
        days = d.split(".")

        pp = p.split(".")
        if len(pp) == 1:
            p = "p{}.0".format(p)
        else:
            p = "p{}".format(p)

        ss = s.split(".")
        if len(ss) == 1:
            s = "s{}.0".format(s)
        else:
            s = "s{}".format(s)

        if(len(days) == 1):
            result = 0
            result += sells.get(d, {}).get(p, {}).get(s, 0)
        else:
            result = 0

            for i in range(int(days[0]), int(days[1]) + 1):
                result += sells.get(str(i), {}).get(p, {}).get(s, 0)

        print(result)
