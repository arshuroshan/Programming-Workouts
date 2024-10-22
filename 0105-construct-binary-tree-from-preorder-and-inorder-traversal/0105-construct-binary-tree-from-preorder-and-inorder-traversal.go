/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func buildTree(preorder []int, inorder []int) *TreeNode {
    if len(preorder) == 0 {
        return nil
    }
    
    inorderMap := make(map[int]int)
    for i, val := range inorder {
        inorderMap[val] = i
    }

    root := &TreeNode{Val: preorder[0]}
    stack := []*TreeNode{root}

    for i := 1; i < len(preorder); i++ {
        node := &TreeNode{Val: preorder[i]}
        if inorderMap[preorder[i]] < inorderMap[stack[len(stack)-1].Val] {
            stack[len(stack)-1].Left = node
        } else {
            var parent *TreeNode
            for len(stack) > 0 && inorderMap[preorder[i]] > inorderMap[stack[len(stack)-1].Val] {
                parent = stack[len(stack)-1]
                stack = stack[:len(stack)-1]
            }
            parent.Right = node
        }
        stack = append(stack, node)
    }

    return root
}