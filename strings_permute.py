from collections import *


def strings_permutations(s1, s2):
    s1_char = defaultdict(int)
    s2_char = defaultdict(int)
    if len(s1) == len(s2):
        for c in s1:
            s1_char[c]+=1
        for c in s2:
            s2_char[c]+=1
        return s1_char==s2_char
    else:
        return False


print(strings_permutations("dab","bad"))
print(strings_permutations("dAb","bad"))
print(strings_permutations("db","bad"))
print(strings_permutations("dab ","bad"))

