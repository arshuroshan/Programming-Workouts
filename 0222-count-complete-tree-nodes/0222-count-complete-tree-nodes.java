class Solution {
    public int countNodes(TreeNode root) {
        if (root == null) {
            return 0;
        }

        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        int nodeCount = 0;
        
        while (!queue.isEmpty()) {
            TreeNode currentNode = queue.poll();
            nodeCount++;
            
            if (currentNode.left != null) {
                queue.offer(currentNode.left);
            }
            if (currentNode.right != null) {
                queue.offer(currentNode.right);
            }
        }
        
        return nodeCount;
    }
}