/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func sumRootToLeaf(root *TreeNode) int {
    var ret int
    if root == nil {
        return ret
    }
    dfs(&ret, root, 0)
    return ret
}

func dfs(ret *int, root *TreeNode, cur int) {
    if root.Left == nil && root.Right == nil {
        if root.Val == 1 {
            *ret += cur*2 + 1
        }else {
            *ret += cur*2
        }
        return
    }
    if root.Left != nil {
        if root.Val == 1 {
            dfs(ret, root.Left, cur*2+1)    
        }else {
            dfs(ret, root.Left, cur*2)
        }
    }
    if root.Right != nil {
        if root.Val == 1 {
            dfs(ret, root.Right, cur*2+1)    
        }else {
            dfs(ret, root.Right, cur*2)
        }
    }    
}
