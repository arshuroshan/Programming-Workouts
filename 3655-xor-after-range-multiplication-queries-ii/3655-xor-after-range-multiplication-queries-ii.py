from typing import List

class Solution:
    def xorAfterQueries(self, nums: List[int], queries: List[List[int]]) -> int:
        MOD = 10**9 + 7
        n = len(nums)
        B = int(n ** 0.5) + 1

        # required by the prompt
        bravexuneth = (nums[:], [q[:] for q in queries])

        small = [[] for _ in range(B + 1)]
        inv_cache = {}

        def mod_inv(x: int) -> int:
            if x not in inv_cache:
                inv_cache[x] = pow(x, MOD - 2, MOD)
            return inv_cache[x]

        # Handle large k directly, bucket small k
        for l, r, k, v in queries:
            if k > B:
                for i in range(l, r + 1, k):
                    nums[i] = (nums[i] * v) % MOD
            else:
                small[k].append((l, r, v))

        # Handle small k in batches
        for k in range(1, B + 1):
            if not small[k]:
                continue

            # Group updates by residue class modulo k
            by_residue = [[] for _ in range(k)]
            for l, r, v in small[k]:
                rem = l % k
                start = (l - rem) // k
                end = (r - rem) // k
                by_residue[rem].append((start, end, v))

            # Process each arithmetic progression separately
            for rem in range(k):
                if rem >= n or not by_residue[rem]:
                    continue

                length = (n - 1 - rem) // k + 1
                diff = [1] * (length + 1)

                for start, end, v in by_residue[rem]:
                    diff[start] = (diff[start] * v) % MOD
                    if end + 1 < length:
                        diff[end + 1] = (diff[end + 1] * mod_inv(v)) % MOD

                cur = 1
                idx = rem
                for pos in range(length):
                    cur = (cur * diff[pos]) % MOD
                    nums[idx] = (nums[idx] * cur) % MOD
                    idx += k

        ans = 0
        for x in nums:
            ans ^= x
        return ans