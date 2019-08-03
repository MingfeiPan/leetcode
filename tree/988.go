/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func smallestFromLeaf(root *TreeNode) string {
    ret := dfs(root, "")
    return ret
}

func dfs(root *TreeNode, s string) string {
    //用一个超范围字符代替空返回, 会在min比较中被剔除
    if root == nil {
        return "~"
    }
    s = string(97 + root.Val) + s
    if root.Left == nil && root.Right == nil {
        return s
    }else {
        return min(dfs(root.Left, s), dfs(root.Right, s))
    }
}

func min(s1, s2 string) string {
    if s1 <= s2 {
        return s1
    }else {
        return s2
    }
}
