class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        count = 0
        for num in nums:
            digits = 0
            if num == 0:
                digits = 1
            else:
                digits = int(math.log10(abs(num))) + 1
            if digits % 2 == 0:
                count += 1
        return count