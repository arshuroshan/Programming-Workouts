class Solution:
    def minSum(self, nums1: List[int], nums2: List[int]) -> int:
        def calculate_sum(nums):
            total = sum(nums)
            zero_count = nums.count(0)
            return total + zero_count, zero_count
        
        sum1, zeros1 = calculate_sum(nums1)
        sum2, zeros2 = calculate_sum(nums2)
        
        if sum1 == sum2:
            return sum1
        elif sum1 < sum2:
            if zeros1 == 0:
                return -1
            return sum2
        else:
            if zeros2 == 0:
                return -1
            return sum1