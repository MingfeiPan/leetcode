/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

type Node struct {
    level int
    Node *TreeNode
}

// bfs
func minDepth(root *TreeNode) int {
    if root == nil {
        return 0
    }
    l := make([]*Node, 0)
    l = append(l, &Node{0, root})
    var t *Node
    for len(l) > 0 {
        t = l[0]
        if t.Node.Left == nil && t.Node.Right == nil {
            return t.level + 1
        }
        l = l[1:]
        if t.Node.Left != nil {
            l = append(l, &Node{t.level+1, t.Node.Left})
        }
        if t.Node.Right != nil {
            l = append(l, &Node{t.level+1, t.Node.Right})
        }
    }
    return 0   
}
