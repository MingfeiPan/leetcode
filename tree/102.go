/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
type Item struct{
    level int 
    t *TreeNode
}

func Slicedelete(s []*Item, index int) []*Item {
    return append([]*Item{}, s[index+1:]...)
}
func levelOrder(root *TreeNode) [][]int {
    ret := make([][]int, 0)
    list := make([]*Item, 0)
    level := 0
    if root == nil {
        return nil
    }
    list = append(list, &Item{0, root})
    for len(list) > 0 {
        temp := make([]int, 0)
        for len(list) > 0 && list[0].level == level {
            root := list[0].t
            list = list[1:]
            
            temp = append(temp, root.Val)
            if root.Left != nil {
                list = append(list, &Item{level+1, root.Left})
            }
            if root.Right != nil {
                list = append(list, &Item{level+1, root.Right})
            }
        }
        ret = append(ret, temp)
        level++
    }
    return ret
}
