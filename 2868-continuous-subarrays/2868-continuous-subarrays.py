from collections import deque

class Solution:
    def continuousSubarrays(self, nums: List[int]) -> int:
        ans = i = 0
        min_deque = deque()
        max_deque = deque()
        
        for j in range(len(nums)):
            while min_deque and nums[min_deque[-1]] > nums[j]:
                min_deque.pop()
            min_deque.append(j)
            
            while max_deque and nums[max_deque[-1]] < nums[j]:
                max_deque.pop()
            max_deque.append(j)

            while nums[max_deque[0]] - nums[min_deque[0]] > 2:
                i += 1
                if min_deque[0] < i:
                    min_deque.popleft()
                if max_deque[0] < i:
                    max_deque.popleft()

            ans += j - i + 1

        return ans