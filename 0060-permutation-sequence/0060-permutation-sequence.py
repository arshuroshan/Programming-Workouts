class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        res, used = [], [0] * (n + 1)
        for i in range(n):
            fact = 1
            for j in range(1, n - i):
                fact *= j
            for j in range(1, n + 1):
                if not used[j]:
                    if k > fact:
                        k -= fact
                    else:
                        res.append(str(j))
                        used[j] = 1
                        break
        return ''.join(res)
