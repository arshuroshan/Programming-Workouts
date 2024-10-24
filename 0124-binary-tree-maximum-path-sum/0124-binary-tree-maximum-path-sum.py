# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        def helper(node: Optional[TreeNode]) -> int:
            if not node:
                return 0

            left_gain = max(helper(node.left), 0)
            right_gain = max(helper(node.right), 0)

            price_newpath = node.val + left_gain + right_gain

            nonlocal max_sum
            max_sum = max(max_sum, price_newpath)

            return node.val + max(left_gain, right_gain)

        max_sum = float('-inf')
        helper(root)
        return max_sum