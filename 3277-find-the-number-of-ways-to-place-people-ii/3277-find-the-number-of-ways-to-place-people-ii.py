class Solution:
    def numberOfPairs(self, points: List[List[int]]) -> int:
        points.sort(key=lambda p: (p[0], -p[1]))
        res = 0
        for i in range(len(points)):
            y1 = points[i][1]
            m = float("-inf")
            for _, y2 in points[i+1:]:
                if m < y2 <= y1:
                    m = y2
                    res += 1
        return res
