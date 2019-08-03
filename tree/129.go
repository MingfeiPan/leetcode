/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func sumNumbers(root *TreeNode) int {
    var ret int
    var cur []int
    dfs(root, &ret, cur)
    return ret
}

func dfs(root *TreeNode, ret *int, cur []int) {
    if root == nil {
        return
    }
    if root.Left == nil && root.Right == nil {
        *ret += sum(append(cur, root.Val))
    }else {
        dfs(root.Left, ret, append(cur, root.Val))
        dfs(root.Right, ret, append(cur, root.Val))
    }
}


func sum(numList []int) int {
    var sum int
    for i := 0; i < len(numList); i++{
        sum += numList[i] * int(math.Pow10(len(numList)-i-1))
    }
    
    return sum
}
