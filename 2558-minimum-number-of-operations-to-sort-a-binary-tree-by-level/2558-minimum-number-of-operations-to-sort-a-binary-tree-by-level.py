# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minimumOperations(self, root: Optional[TreeNode]) -> int:
        
        def countSwaps(arr):
            sorted_positions = {val: i for i, val in enumerate(sorted(arr))}
            visited = [False] * len(arr)
            swaps = 0
            
            for i in range(len(arr)):
                if visited[i] or sorted_positions[arr[i]] == i:
                    continue
                
                cycle_size = 0
                x = i
                while not visited[x]:
                    visited[x] = True
                    x = sorted_positions[arr[x]]
                    cycle_size += 1
                
                if cycle_size > 1:
                    swaps += cycle_size - 1
            
            return swaps

        queue = deque([root])
        total_operations = 0
        
        while queue:
            current_level = []
            for _ in range(len(queue)):
                node = queue.popleft()
                current_level.append(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            
            total_operations += countSwaps(current_level)
        
        return total_operations