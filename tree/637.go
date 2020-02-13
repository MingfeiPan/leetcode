/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func averageOfLevels(root *TreeNode) []float64 {
    sum := make([]float64, 0)
    count := make([]float64, 0)
    dfs(&sum, &count, root, 0)
    for i, _ := range sum {
        sum[i] = sum[i] / count[i]
    }
    return sum
}

func dfs(ret *[]float64, count *[]float64, root *TreeNode, level int){
    if root == nil {
        return
    }
    if len(*ret) == level {
        *ret = append(*ret, 0.0)
        *count = append(*count, 0.0)
    }
    (*ret)[level] += float64(root.Val)
    (*count)[level] += 1
    if root.Left != nil {
        dfs(ret, count, root.Left, level+1)
    }
    if root.Right != nil {
        dfs(ret, count, root.Right, level+1)
    }
}
