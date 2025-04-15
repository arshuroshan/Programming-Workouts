from sortedcontainers import SortedList

class Solution:
    def goodTriplets(self, nums1: List[int], nums2: List[int]) -> int:
        pos = {v: i for i, v in enumerate(nums2)}
        
        n = len(nums1)
        prefix = [0] * n
        suffix = [0] * n
        
        sl = SortedList()
        for i in range(n):
            p = pos[nums1[i]] + 1
            prefix[i] = sl.bisect_left(p)
            sl.add(p)
        
        sl = SortedList()
        for i in range(n-1, -1, -1):
            p = pos[nums1[i]] + 1
            suffix[i] = len(sl) - sl.bisect_right(p)
            sl.add(p)
        
        return sum(prefix[i] * suffix[i] for i in range(n))