/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func flatten(root *TreeNode)  {
	if root == nil {
		return
	}
    head := TreeNode{-1, nil, nil}
    dummy := &head
	list := make([]*TreeNode, 0)
	list = append(list, root)
	for len(list) > 0 {
		root = list[len(list)-1]
		list = list[:len(list)-1]
        dummy.Right = root
        dummy.Left = nil
        dummy = root
		if root.Right != nil {
			list = append(list, root.Right)
		}
		if root.Left != nil {
			list = append(list, root.Left)
		}
	}
    root = head.Right
	return    
}
