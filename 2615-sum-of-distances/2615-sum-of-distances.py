from collections import defaultdict
from itertools import accumulate

class Solution:
    def distance(self, nums):
        pos = defaultdict(list)
        for i, v in enumerate(nums):
            pos[v].append(i)

        res = [0] * len(nums)

        for indices in pos.values():
            prefix = [0] + list(accumulate(indices))
            total = prefix[-1]
            n = len(indices)

            for i, idx in enumerate(indices):
                left = idx * i - prefix[i]
                right = (total - prefix[i + 1]) - idx * (n - i - 1)
                res[idx] = left + right

        return res