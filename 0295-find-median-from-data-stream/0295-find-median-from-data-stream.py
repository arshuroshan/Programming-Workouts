import heapq

class MedianFinder:

    def __init__(self):
        self.minq = []
        self.maxq = []

    def addNum(self, num: int) -> None:
        heapq.heappush(self.maxq, -num)

        heapq.heappush(self.minq, -heapq.heappop(self.maxq))

        if len(self.minq) - len(self.maxq) > 1:
            heapq.heappush(self.maxq, -heapq.heappop(self.minq))

    def findMedian(self) -> float:
        if len(self.minq) == len(self.maxq):
            return (self.minq[0] - self.maxq[0]) / 2.0
        return float(self.minq[0])