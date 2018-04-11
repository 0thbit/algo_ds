from collections import defaultdict


def remove_alternate_char(inp_str):
    """ Takes in a string as an input and returns a string removing alternate characters """

    seen_before = defaultdict(bool)
    new_str = []

    for c in inp_str:
        if seen_before[c]:  # skip add c to new_str
            seen_before[c] = False
        else:
            new_str.append(c)
            seen_before[c] = True

    return "".join(new_str)


def main():
    s = remove_alternate_char("aaaa")  # aa
    print(s)
    s = remove_alternate_char("abcd")  # abcd
    print(s)
    s = remove_alternate_char("aa aa")  # a a
    print(s)
    s = remove_alternate_char("")  # ""
    print(s)
    s = remove_alternate_char("b a c")  # b ac
    print(s)
    s = remove_alternate_char("0a0")  # 0a
    print(s)


if __name__ == "__main__":
    main()



