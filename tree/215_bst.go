type TreeNode struct{
    Val int
    Left *TreeNode
    Right *TreeNode
}

func (t *TreeNode) insert (val int) *TreeNode {
    if t == nil {
        t = &TreeNode{val, nil, nil}
        return t
    }
    if val < t.Val {
        t.Left = t.Left.insert(val)
    }else {
        t.Right = t.Right.insert(val)
    }
    return t
}

func (t *TreeNode) getmax() *TreeNode {
    if t == nil {
        return t
    }
    for {
        if t.Right == nil {
            return t
        }else {
            t = t.Right
        }
    }
}

func (t *TreeNode) delete (val int) *TreeNode {
    if t == nil {
        return t
    }
    if val < t.Val {
        t.Left = t.Left.delete(val)
    } else if val > t.Val {
        t.Right = t.Right.delete(val)
    }else {
        if t.Left != nil && t.Right != nil {
            t.Val = t.Left.getmax().Val
            t.Left = t.Left.delete(t.Val)
        }else if t.Left == nil && t.Right == nil {
            t = nil
        }else if t.Left == nil {
            t = t.Right
        }else {
            t = t.Left
        }
    }
    return t
}
func findKthLargest(nums []int, k int) int {
    var root *TreeNode
    for _, v := range nums {
        root = root.insert(v)
    }
    for k > 1 {
        root = root.delete(root.getmax().Val)
        k--
    }
    return root.getmax().Val
}


