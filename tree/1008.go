/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func bstFromPreorder(preorder []int) *TreeNode {
    if len(preorder) == 0 {
        return nil
    }
    root := &TreeNode{preorder[0], nil, nil}
    if len(preorder) == 1 {
        return root
    }
    pivot := 1
    for pivot < len(preorder) && preorder[pivot] < preorder[0] {
        pivot++
    }
    root.Left = bstFromPreorder(preorder[1:pivot])
    root.Right = bstFromPreorder(preorder[pivot:])
    return root
}

