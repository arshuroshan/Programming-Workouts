class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []
        
        digit_to_letters = ["abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]

        def backtrack(index: int) -> List[str]:
            if index == len(digits):
                return [""]
            
            letters = digit_to_letters[int(digits[index]) - 2]
            combinations = backtrack(index + 1)
            return [letter + combination for letter in letters for combination in combinations]
        
        return backtrack(0)