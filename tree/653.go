/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func findTarget(root *TreeNode, k int) bool {
    l := make([]int, 0)
    rootl := make([]*TreeNode, 0)
    for {
        for root != nil {
            rootl = append(rootl, root)
            root = root.Left
        }
        if len(rootl) == 0 {
            break
        }
        root = rootl[len(rootl)-1]
        l = append(l, root.Val)
        rootl = rootl[:len(rootl)-1]
        root = root.Right
    }

    i := 0
    j := len(l) - 1
    for i < j {
        if l[i] + l[j] == k {
            return true
        }else if l[i] + l[j] < k {
            i++
        }else {
            j--
        }
    }
    return false
    
}
