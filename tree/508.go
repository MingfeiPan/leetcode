/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */


func findFrequentTreeSum(root *TreeNode) []int {
    if root == nil {
        return nil
    }
    var (
        index int
        ret []int
    )
    RetMap := make(map[int]int)
    findSum(root, &RetMap)
    fmt.Println(RetMap)
    for _, l := range RetMap {
        if l > index {
            index = l
        }
    }
    for i, l := range RetMap {
        if index == l {
            ret = append(ret, i)
        }
    }
    return ret
}

func findSum(root *TreeNode, retMap *map[int]int) int{
    ret := root.Val
    if root.Left != nil {
        //自底向上累加
        ret += findSum(root.Left, retMap)
    }
    
    if root.Right != nil {
        ret += findSum(root.Right, retMap)
    }
    //加入结果集
    if _, ok := (*retMap)[ret]; !ok {
        (*retMap)[ret] = 1
    }else {
        (*retMap)[ret]++
    }
    //返回该节点的结果
    return ret
}
