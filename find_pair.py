""" Given an array in sorted order, find a pair whose sum matches the target sum """


# 2 3 3 4 6 | 7
# 2 3 3 4 5 | 7


def findPair(sorted_arr, target_sum):
    lp = 0
    rp = len(sorted_arr) - 1
    while 0 <= lp < rp < len(sorted_arr):
        curr_sum = sorted_arr[lp] + sorted_arr[rp]
        if curr_sum == target_sum:
            return sorted_arr[lp], sorted_arr[rp]
        elif curr_sum > target_sum:
            rp -= 1
        else:
            lp += 1
    return None, None


t1 = findPair([2, 3, 3, 4, 6], 7)
t2 = findPair([2, 3, 3, 4, 5], 4)
print(t2)
