from bisect import bisect_left

class Solution:
    def maxDistance(self, side: int, points: List[List[int]], k: int) -> int:
        arr = []
        for x, y in points:
            if x == 0:
                v = y
            elif y == side:
                v = side + x
            elif x == side:
                v = 3 * side - y
            else:
                v = 4 * side - x
            arr.append(v)

        arr.sort()
        n = len(arr)
        perim = 4 * side

        def feasible(d):
            for i in range(n):
                limit = arr[i] + perim - d
                cur = arr[i]
                cnt = 1
                while cnt < k:
                    idx = bisect_left(arr, cur + d)
                    if idx == n or arr[idx] > limit:
                        break
                    cur = arr[idx]
                    cnt += 1
                if cnt == k:
                    return True
            return False

        lo, hi = 1, side
        while lo < hi:
            mid = (lo + hi + 1) // 2
            if feasible(mid):
                lo = mid
            else:
                hi = mid - 1

        return lo