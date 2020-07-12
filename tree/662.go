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
    Posi int
    Level int
}
func widthOfBinaryTree(root *TreeNode) int {
    if root == nil {
        return 0
    }
    var flag, ret, cur int
    cur, ret = 1, 1
    s := make([]Item, 0)
    s = append(s, Item{root, 1, 0})
    for len(s) > 0 {
        item := s[0]
        s = s[1:]
        if flag != item.Level {
            cur = item.Posi
            flag = item.Level
        }else {
            if ret < item.Posi - cur + 1 {
                ret = item.Posi - cur + 1
            }
        }
        if item.Node.Left != nil {
            s = append(s, Item{item.Node.Left, item.Posi*2, item.Level+1})
        }
        if item.Node.Right != nil {
            s = append(s, Item{item.Node.Right, item.Posi*2+1, item.Level+1})
        }
    }
    return ret
}
