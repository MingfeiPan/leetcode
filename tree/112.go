/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func hasPathSum(root *TreeNode, sum int) bool {
    if root == nil {
        return false
    }
    return dfs(root, sum)
}

func dfs(root *TreeNode, left int) bool{
    if root.Left == nil && root.Right == nil {
        return left == root.Val
    }
    if root.Left != nil && root.Right != nil {
        return dfs(root.Left, left - root.Val) || dfs(root.Right, left - root.Val)
    }
    if root.Left != nil {
        return dfs(root.Left, left - root.Val)
    }
    if root.Right != nil {
        return dfs(root.Right, left - root.Val)
    }
    return false
}
