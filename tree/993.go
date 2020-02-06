/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isCousins(root *TreeNode, x int, y int) bool {
    if root == nil {
        return false
    }
    parentX, depthX := findNode(root, nil, 0, x)
    parentY, depthY := findNode(root, nil, 0, y)
    if parentX != parentY && depthX == depthY {
        return true
    }else {
        return false
    }
    
}

func findNode(root *TreeNode, parent *TreeNode, depth int, val int) (retp *TreeNode, retd int) {
    if root.Val == val {
        retp = parent
        retd = depth
    }else{
        if root.Left != nil {
            retp, retd = findNode(root.Left, root, depth+1, val)   
            
        }
        if retp != nil {
            return retp, retd
        }        
        if root.Right != nil {
            retp, retd = findNode(root.Right, root, depth+1, val)    
        }
    }
    return retp, retd
}
