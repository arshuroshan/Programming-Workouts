# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        if not nums:
            return None
        stack = [(0, len(nums) - 1, None, None)]
        root = None
        
        while stack:
            l, r, parent, is_left_child = stack.pop()
            if l > r:
                continue
            
            mid = (l + r) // 2
            node = TreeNode(nums[mid])
            
            if parent:
                if is_left_child:
                    parent.left = node
                else:
                    parent.right = node
            else:
                root = node
            stack.append((mid + 1, r, node, False))
            stack.append((l, mid - 1, node, True))
        
        return root