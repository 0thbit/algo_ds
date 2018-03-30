def max_sum_subarray(arr):
    max_so_far = 0
    max_ending_here = 0

    for e in arr:
        max_ending_here += e
        if max_ending_here < 0:
            max_ending_here = 0
        if max_so_far < max_ending_here:
            max_so_far = max_ending_here
    return max_so_far


def main():
    l = [-2, -3, 4, -1, -2, 1, 5, -3]
    print(max_sum_subarray(l)) # 7

if __name__ == '__main__':
    main()
