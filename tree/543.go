/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func diameterOfBinaryTree(root *TreeNode) int {
    if root == nil {
        return 0
    }
    var ret int
    dfs(root, &ret)
    return ret - 1
}

func dfs(root *TreeNode, ret *int) int {
    if root == nil {
        return 0
    }
    left := dfs(root.Left, ret)
    right := dfs(root.Right, ret)
    if left + right + 1 > *ret {
        *ret = left + right + 1
    }
    if left > right {
        return left + 1
    }else {
        return right + 1
    }
}
