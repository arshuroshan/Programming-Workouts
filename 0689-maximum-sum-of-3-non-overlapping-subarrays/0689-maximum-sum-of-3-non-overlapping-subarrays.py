class Solution:
    def maxSumOfThreeSubarrays(self, nums: List[int], k: int) -> List[int]:
        subarray_sums = [sum(nums[i:i+k]) for i in range(len(nums) - k + 1)]

        left = [0] * len(subarray_sums)
        max_idx = 0
        for i in range(len(subarray_sums)):
            if subarray_sums[i] > subarray_sums[max_idx]:
                max_idx = i
            left[i] = max_idx

        right = [0] * len(subarray_sums)
        max_idx = len(subarray_sums) - 1
        for i in range(len(subarray_sums) - 1, -1, -1):
            if subarray_sums[i] >= subarray_sums[max_idx]:
                max_idx = i
            right[i] = max_idx

        best_sum = 0
        result = []
        for j in range(k, len(subarray_sums) - k):
            i = left[j - k]
            l = right[j + k]
            current_sum = subarray_sums[i] + subarray_sums[j] + subarray_sums[l]
            if current_sum > best_sum:
                best_sum = current_sum
                result = [i, j, l]

        return result