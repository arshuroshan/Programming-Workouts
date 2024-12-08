class Solution:
    def maxTwoEvents(self, events: List[List[int]]) -> int:
        events.sort()
        n = len(events)
        max_value = [0] * (n + 1)

        for i in range(n - 1, -1, -1):
            max_value[i] = max(max_value[i + 1], events[i][2])
        
        result = 0
        for i in range(n):
            left, right = i + 1, n
            while left < right:
                mid = (left + right) // 2
                if events[mid][0] > events[i][1]:
                    right = mid
                else:
                    left = mid + 1
            
            result = max(result, events[i][2] + max_value[left])
        
        return result