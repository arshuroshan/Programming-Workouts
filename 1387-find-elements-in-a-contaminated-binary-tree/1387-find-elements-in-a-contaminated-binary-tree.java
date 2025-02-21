class FindElements {
    private TreeNode root;

    public FindElements(TreeNode root) {
        this.root = root;
        recover(root, 0);
    }

    private void recover(TreeNode node, int val) {
        if (node == null) return;
        node.val = val;
        recover(node.left, 2 * val + 1);
        recover(node.right, 2 * val + 2);
    }

    public boolean find(int target) {
        return findInTree(root, target);
    }

    private boolean findInTree(TreeNode node, int target) {
        if (node == null) return false;
        if (node.val == target) return true;
        return findInTree(node.left, target) || findInTree(node.right, target);
    }
}