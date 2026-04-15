class Solution:
    def closestTarget(self, words: List[str], target: str, startIndex: int) -> int:
        n = len(words)
        
        for step in range(n):
            left = (startIndex - step) % n
            right = (startIndex + step) % n
            
            if words[left] == target or words[right] == target:
                return step
        
        return -1