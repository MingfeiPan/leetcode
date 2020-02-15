/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

type Item struct {
    level int
    t *TreeNode
}
func zigzagLevelOrder(root *TreeNode) [][]int {
    ret := make([][]int, 0)
    if root == nil {
        return ret
    }
    queue := make([]*Item, 0)
    queue = append(queue, &Item{0, root})
    for len(queue) > 0 {
        item := queue[0]
        queue = queue[1:]
        if item.level == len(ret) {
            ret = append(ret, []int{})
        }
        ret[item.level] = append(ret[item.level], item.t.Val)
        if item.t.Left != nil {
            queue = append(queue, &Item{item.level+1, item.t.Left})
        }
        if item.t.Right != nil {
            queue = append(queue, &Item{item.level+1, item.t.Right})
        }
    }
    for index := 1; index < len(ret); index += 2 {
        for i, j := 0, len(ret[index])-1; i < j; i, j = i+1, j-1 {
            ret[index][i], ret[index][j] = ret[index][j], ret[index][i]
        }
    }
    return ret
 }
