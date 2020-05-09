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

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isCousins(root *TreeNode, x int, y int) bool {
    var depthx, depthy int
    var prex, prey *TreeNode
    dfs(root, nil, 0, x, y, &depthx, &depthy, &prex, &prey)
    if depthx == depthy && prex != prey {
        return true
    }
    return false
}

func dfs(root *TreeNode, pre *TreeNode, depth int, x int, y int, depthx *int, depthy *int, prex **TreeNode, prey **TreeNode) {
    if root == nil {
        return
    }
    if root.Val == x {
        *depthx = depth
        *prex = pre
        return
    }else if root.Val == y {
        *depthy = depth
        *prey = pre
        return
    }else {
        dfs(root.Left, root, depth+1, x, y, depthx, depthy, prex, prey)
        dfs(root.Right, root, depth+1, x, y, depthx, depthy, prex, prey)
    }
}
