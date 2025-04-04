class Solution {
    private TreeNode lca;
    private int maxDepth;

    public TreeNode lcaDeepestLeaves(TreeNode root) {
        lca = null;
        maxDepth = 0;
        findDepth(root, 0);
        return lca;
    }

    private int findDepth(TreeNode node, int depth) {
        if (node == null) return depth - 1;
        
        int leftDepth = findDepth(node.left, depth + 1);
        int rightDepth = findDepth(node.right, depth + 1);
        
        if (leftDepth == rightDepth && leftDepth >= maxDepth) {
            maxDepth = leftDepth;
            lca = node;
        }
        
        return Math.max(leftDepth, rightDepth);
    }
}