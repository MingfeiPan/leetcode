/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func pseudoPalindromicPaths (root *TreeNode) int {
    if root == nil {
        return 0
    }
    l := make([]int, 9)
    var ret int
    dfs(root, l, &ret)
    return ret
}

func dfs(root *TreeNode, l []int, ret *int) {
    l[root.Val-1]++
    if root.Left == nil && root.Right == nil {
        if checkPalin(l) {
            (*ret)++   
        }
    }else { 
        if root.Left != nil {
            dfs(root.Left, l, ret)
            l[root.Left.Val-1]--
        }
        if root.Right != nil {
            dfs(root.Right, l, ret)
            l[root.Right.Val-1]--
        }
    }
}

func checkPalin(l []int) bool {
    var count_odd, count_even int
    for _, i := range l {
        if i % 2 != 0 {
            count_odd++
        }else {
            count_even++
        }
    }
    if count_odd == 0 || count_odd == 1 && count_even > 0 {
        return true
    }
    return false
}
