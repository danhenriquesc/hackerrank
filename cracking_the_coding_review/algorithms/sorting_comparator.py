from functools import cmp_to_key


class Player:
    def __init__(self, name, score):
        self.name = name
        self.score = score

    def __repr__(self):
        return str(self.score)

    def comparator(a, b):
        if (a.score != b.score):
            return (int(b.score) - int(a.score))
        else:
            return -1 if a.name < b.name else 1
