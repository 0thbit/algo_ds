"""Given an integer array and a positive integer k, count all distinct pairs with difference equal to k."""
from collections import defaultdict


def diff_of_k(list_, diff) -> list:
    d = defaultdict(bool)

    valid_l = []
    for e in list_:
        if d[e - diff] == True:
            valid_l.append((e, e - diff))
        if d[e + diff] == True:
            valid_l.append((e, e + diff))
        d[e] = True

    return valid_l


def main():
    l = [1, 5, 3, 4, 2]
    k = 3
    print(diff_of_k(l, k))
    l = [8, 12, 16, 4, 0, 20]
    k = 4
    print(diff_of_k(l, k))


if __name__ == '__main__':
    main()
