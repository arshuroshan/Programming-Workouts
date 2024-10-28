class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null) {
            return null;
        }

        if (root == p || root == q) {
            return root;
        }
        
        TreeNode leftSubtree = lowestCommonAncestor(root.left, p, q);
        TreeNode rightSubtree = lowestCommonAncestor(root.right, p, q);
        
        if (leftSubtree != null && rightSubtree != null) {
            return root;
        }
        
        return (leftSubtree != null) ? leftSubtree : rightSubtree;
    }
}