class Solution:
    def longestCommonPrefix(self, arr1: List[int], arr2: List[int]) -> int:
        prefixes = {}
        for number in arr1:
            prefix = ""
            for digit in str(number):
                prefix += digit
                prefixes[prefix] = True
        
        max_length = 0
        for number in arr2:
            prefix = ""
            for digit in str(number):
                prefix += digit
                if prefix in prefixes:
                    max_length = max(max_length, len(prefix))
        
        return max_length