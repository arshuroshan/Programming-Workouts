class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        if not points:
            return 0
        points.sort(key=lambda x: x[1])
        ans = 1
        last_end = points[0][1]
        for start, end in points[1:]:
            if start > last_end:
                ans += 1
                last_end = end
        return ans