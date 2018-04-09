def fibonacci_num():
    x, y = 1, 1  # 1,1,2
    while True:
        yield x
        x, y = y, x + y


def main():
    it = fibonacci_num()
    for i in range(10):
        print(it.__next__(), end=" ")


if __name__ == '__main__':
    main()