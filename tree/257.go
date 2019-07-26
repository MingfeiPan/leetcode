/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
import (
    "strconv"
)
func binaryTreePaths(root *TreeNode) []string {
    if root == nil {
        return nil
    }
    ret := make([]string, 0)
    var str string
    dfs(root, &ret, str)
    return ret
}

func dfs(root *TreeNode, ret *[]string, str string) {
    var newStr string
    if str == "" {
        newStr = strconv.Itoa(root.Val)
    }else {
        newStr = str + "->" + strconv.Itoa(root.Val)
    }
    if root.Left == nil && root.Right == nil {
        *ret = append(*ret, newStr)    
    }
    if root.Left != nil {
        dfs(root.Left, ret, newStr)
    }
    if root.Right != nil {
        dfs(root.Right, ret, newStr)
    }
}
