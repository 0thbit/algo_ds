""" 1 1 2 1, 2 return 7"""
from collections import defaultdict


def task_scheduler(task_arr, recovery_interval):
    curr_cycle = 0

    cooldown = defaultdict(int)

    id = 0
    while id < len(task_arr):
        task = task_arr[id]
        curr_cycle += 1
        for key in cooldown.keys():
            cooldown[key] -= 1
        if task in cooldown.keys():
            pass
        else:
            cooldown[task] = recovery_interval
            id += 1

        cooldown = {key: val for key, val in cooldown.items() if val != 0}

    return curr_cycle


def main():
    arr = [1, 2, 3, 1, 2, 3]
    cooldown = 3
    x = task_scheduler(arr, cooldown)
    print(x)


if __name__ == '__main__':
    main()
