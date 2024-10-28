/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val === undefined ? 0 : val)
 *     this.left = (left === undefined ? null : left)
 *     this.right = (right === undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var rightSideView = function(root) {
    const result = [];
    if (!root) {
        return result;
    }

    const queue = [];
    queue.push(root);

    while (queue.length > 0) {
        const levelSize = queue.length;
        result.push(queue[queue.length - 1].val);

        for (let i = 0; i < levelSize; i++) {
            const currentNode = queue.shift();

            if (currentNode.left) {
                queue.push(currentNode.left);
            }
            if (currentNode.right) {
                queue.push(currentNode.right);
            }
        }
    }

    return result;
};