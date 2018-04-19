""" Running median """

import heapq


class Sequence(object):

    def __init__(self):
        self.minh = []
        self.maxh = []
        self.maxcnt = 0
        self.mincnt = 0
        self.median = 0.0

    def add_element(self, x):
        """ Will add an element and update the median """

        if self.mincnt == 0:
            # First element always pushed to minh
            heapq.heappush(self.minh, x)
            self.mincnt += 1
            self.median = x

        elif x > self.median:
            # x goes in minh
            if self.mincnt == self.maxcnt:
                heapq.heappush(self.minh, x)
                self.mincnt += 1
                self.median = self.minh[0]
            elif self.mincnt > self.maxcnt:
                heapq.heappush(self.maxh, -1 * heapq.heappushpop(self.minh, x))
                self.maxcnt += 1
                self.median = (self.minh[0] - self.maxh[0]) / 2
            elif self.mincnt < self.maxcnt:
                heapq.heappush(self.minh, x)
                self.mincnt += 1
                self.median = (self.minh[0] - self.maxh[0]) / 2

        else:
            # x goes in maxh

            if self.mincnt == self.maxcnt:
                heapq.heappush(self.maxh, -1 * x)
                self.maxcnt += 1
                self.median = -1 * self.maxh[0]
            elif self.maxcnt > self.mincnt:
                heapq.heappush(self.minh, -1 * heapq.heappushpop(self.maxh, -1 * x))
                self.mincnt += 1
                self.median = (self.minh[0] - self.maxh[0]) / 2
            elif self.maxcnt < self.mincnt:
                heapq.heappush(self.maxh, -1 * x)
                self.maxcnt += 1
                self.median = (self.minh[0] - self.maxh[0]) / 2

        print(float(self.median))


seq = Sequence()
arr = [5, 15, 1, 3]

for el in arr:
    seq.add_element(el)
