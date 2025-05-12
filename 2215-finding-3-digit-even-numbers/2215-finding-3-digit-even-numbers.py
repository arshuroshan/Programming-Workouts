from collections import Counter

class Solution:
    def findEvenNumbers(self, digits: List[int]) -> List[int]:
        digit_counts = Counter(digits)
        res = set()
        
        def backtrack(path):
            if len(path) == 3:
                num = int(''.join(map(str, path)))
                res.add(num)
                return
            
            for d in range(10):
                if digit_counts[d] == 0:
                    continue
                if len(path) == 0 and d == 0:
                    continue
                if len(path) == 2 and d % 2 != 0:
                    continue
                
                digit_counts[d] -= 1
                backtrack(path + [d])
                digit_counts[d] += 1
        
        backtrack([])
        return sorted(res)