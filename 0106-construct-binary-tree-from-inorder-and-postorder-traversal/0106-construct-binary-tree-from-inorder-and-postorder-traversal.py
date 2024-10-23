# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        if not inorder or not postorder:
            return None

        root = TreeNode(postorder[-1])
        stack = [root]
        inorder_index = len(inorder) - 1

        for postorder_index in range(len(postorder) - 2, -1, -1):
            node = stack[-1]
            value = postorder[postorder_index]

            if node.val != inorder[inorder_index]:
                node.right = TreeNode(value)
                stack.append(node.right)
            else:
                while stack and stack[-1].val == inorder[inorder_index]:
                    node = stack.pop()
                    inorder_index -= 1
                node.left = TreeNode(value)
                stack.append(node.left)

        return root