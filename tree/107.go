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

func levelOrderBottom(root *TreeNode) [][]int {
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
    for i, j := 0, len(ret)-1; i < j; i, j = i+1, j-1 {
        ret[i], ret[j] = ret[j], ret[i]
    }
    return ret
}

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

type Item struct {
    Node *TreeNode
    Level int
}
func levelOrderBottom(root *TreeNode) [][]int {
    ret := make([][]int, 0)
    if root == nil {
        return ret
    }
    stack := make([]Item, 0)
    stack = append(stack, Item{root, 0})
    for len(stack) > 0 {
        cur := stack[0]
        stack = stack[1:]
        if len(ret) <= cur.Level {
            ret = append(ret, make([]int, 0))
        }
        ret[cur.Level] = append(ret[cur.Level], cur.Node.Val)
        if cur.Node.Left != nil {
            stack = append(stack, Item{cur.Node.Left, cur.Level+1})
        }
        if cur.Node.Right != nil {
            stack = append(stack, Item{cur.Node.Right, cur.Level+1})
        }
    }
    for i, j := 0, len(ret)-1; i < j; i, j = i+1, j-1 {
        ret[i], ret[j] = ret[j], ret[i]
    }
    return ret
}
