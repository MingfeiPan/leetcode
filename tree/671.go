/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func findSecondMinimumValue(root *TreeNode) int {
	//注意这道题需要遍历整个搜索树, 因为树左右深度可能不同, bfs期望会遍历所有节点平均复杂度o(n), dfs会快一些, 最坏复杂度o(n)
    if root == nil {
        return -1
    }
    queue := make([]*TreeNode, 0)
    first, second, flag := root.Val, math.MaxInt64, false
    var cur *TreeNode
    queue = append(queue, root)
    for len(queue) > 0 {
        cur = queue[len(queue)-1]
        // queue = queue[1:]
        queue = queue[:len(queue)-1]
        if cur.Val != first && cur.Val < second {
            second = cur.Val
            flag = true
        }
        if cur.Left != nil {
            queue = append(queue, cur.Left, cur.Right)
        }
    }
    if flag {
        return second
    }else {
        return -1
    }
    
}
