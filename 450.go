/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func deleteNode(root *TreeNode, key int) *TreeNode {
    if root != nil {
        if key < root.Val {
            root.Left = deleteNode(root.Left, key)
        }else if key > root.Val {
            root.Right = deleteNode(root.Right, key)
        }else {
            if root.Left != nil && root.Right != nil {
                // found
                root.Val = getMin(root.Right).Val
                root.Right = deleteNode(root.Right, root.Val)
            }else if root.Left == nil && root.Right == nil {
                root = nil
            }else if root.Left == nil {
                root = root.Right
            }else {
                root = root.Left
            }
        }
    }
    return root
}

func getMin(this *TreeNode) *TreeNode {
    if this == nil {
        return nil
    }
    for {
        if this.Left == nil {
            return this
        }
        this = this.Left
    }
}
