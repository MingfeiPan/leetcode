/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func rangeSumBST(root *TreeNode, L int, R int) int {
    var (
        ret int
        tl []*TreeNode
    )
    tl = append(tl, root)
    for len(tl) > 0 {
        root = tl[len(tl)-1]
        tl = tl[:len(tl)-1]
        if root.Val < L {
            if root.Right != nil {
                tl = append(tl, root.Right)    
            }
        }else if root.Val > R{
            if root.Left != nil{
                tl = append(tl, root.Left)
            }
        }else {
            ret += root.Val
            if root.Left != nil {
                tl = append(tl, root.Left)
            }
            if root.Right != nil {
                tl = append(tl, root.Right)    
            }
        }
    }
    return ret
}
