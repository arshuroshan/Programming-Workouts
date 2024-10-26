class Solution:
    def treeQueries(self, root: Optional[TreeNode], queries: List[int]) -> List[int]:
        def calculateDepths(node):
            if not node:
                return 0
            left_depth = calculateDepths(node.left)
            right_depth = calculateDepths(node.right)
            node_depth[node] = 1 + max(left_depth, right_depth)
            return node_depth[node]

        def dfsTraversal(node, current_depth, max_depth):
            if not node:
                return
            current_depth += 1
            result[node.val] = max_depth
            dfsTraversal(node.left, current_depth, max(max_depth, current_depth + node_depth.get(node.right, 0)))
            dfsTraversal(node.right, current_depth, max(max_depth, current_depth + node_depth.get(node.left, 0)))

        node_depth = defaultdict(int)
        calculateDepths(root)
        result = [0] * (len(node_depth) + 1)
        dfsTraversal(root, -1, 0)
        return [result[v] for v in queries]