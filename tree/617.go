/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func mergeTrees(t1 *TreeNode, t2 *TreeNode) *TreeNode {
    if t1 != nil && t2 != nil {
        newNode := &TreeNode{0, nil, nil}
        newNode.Val = t1.Val + t2.Val
        newNode.Left = mergeTrees(t1.Left, t2.Left)
        newNode.Right = mergeTrees(t1.Right, t2.Right)            
        return newNode
    }
    if t1 == nil {
        return t2
        // newNode.Val = t2.Val
        // newNode.Left = mergeTrees(nil, t2.Left)
        // newNode.Right = mergeTrees(nil, t2.Right)
    }
    if t2 == nil {
        return t1
        // newNode.Val = t1.Val
        // newNode.Left = mergeTrees(nil, t1.Left)
        // newNode.Right = mergeTrees(nil, t1.Right)        
    }
    return nil
}
