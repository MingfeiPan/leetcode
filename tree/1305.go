/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func getAllElements(root1 *TreeNode, root2 *TreeNode) []int {
    s1 := make([]*TreeNode, 0)
    s2 := make([]*TreeNode, 0)
    ret := make([]int, 0)
    for root1 != nil {
        s1 = append(s1, root1)
        root1 = root1.Left
    }
    for root2 != nil {
        s2 = append(s2, root2)
        root2 = root2.Left
    }    
    for {
        if len(s1) == 0 || len(s2) == 0 {
            break
        }
        root1 = s1[len(s1)-1]
        root2 = s2[len(s2)-1]
        if root1.Val < root2.Val {
            ret = append(ret, root1.Val)
            s1 = s1[:len(s1)-1]
            root1 = root1.Right
            for root1 != nil {
                s1 = append(s1, root1)
                root1 = root1.Left
            }            
        }else {
            ret = append(ret, root2.Val)
            s2 = s2[:len(s2)-1]
            root2 = root2.Right
            for root2 != nil {
                s2 = append(s2, root2)
                root2 = root2.Left
            }            
        }
    }
    if len(s1) > 0 {
        for {
            if len(s1) == 0 {
                break
            }
            root1 = s1[len(s1)-1]
            ret = append(ret, root1.Val)
            s1 = s1[:len(s1)-1]
            root1 = root1.Right  
            for root1 != nil {
                s1 = append(s1, root1)
                root1 = root1.Left
            }            
        }
    }else {
        for {
            if len(s2) == 0 {
                break
            }
            root2 = s2[len(s2)-1]
            ret = append(ret, root2.Val)
            s2 = s2[:len(s2)-1]
            root2 = root2.Right
            for root2 != nil {
                s2 = append(s2, root2)
                root2 = root2.Left
            }            
        }        
    }

    return ret
}
