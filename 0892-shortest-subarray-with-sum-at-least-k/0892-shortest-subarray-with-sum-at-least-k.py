class Solution:
    def shortestSubarray(self, nums: List[int], k: int) -> int:
        s = [0]
        for num in nums:
            s.append(s[-1] + num)
        q = deque()
        ans = float('inf')
        
        for i, v in enumerate(s):
            while q and v - s[q[0]] >= k:
                ans = min(ans, i - q.popleft())
            while q and s[q[-1]] >= v:
                q.pop()
            q.append(i)
        
        return -1 if ans == float('inf') else ans