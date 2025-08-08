class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        def dfs(i, s):
            if s == 0:
                res.append(path[:])
                return
            if i >= len(candidates) or s < candidates[i]:
                return
            for j in range(i, len(candidates)):
                if j > i and candidates[j] == candidates[j - 1]:
                    continue
                path.append(candidates[j])
                dfs(j + 1, s - candidates[j])
                path.pop()
        candidates.sort()
        res, path = [], []
        dfs(0, target)
        return res
