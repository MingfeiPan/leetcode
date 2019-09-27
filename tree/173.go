/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
type BSTIterator struct {
    list []int
    size int
}


func Constructor(root *TreeNode) BSTIterator {
    var it BSTIterator
    l := make([]*TreeNode, 0)
    for {
        for root != nil {
            l = append(l, root)
            root = root.Left
        }
        if len(l) == 0 {
            break
        }
        root = l[len(l)-1]
        l = l[:len(l)-1]
        it.list = append(it.list, root.Val)
        it.size++
        root = root.Right
    }
    return it
}


/** @return the next smallest number */
func (this *BSTIterator) Next() int {
    this.size--
    ret := this.list[0]
    this.list = this.list[1:]
    return ret
}


/** @return whether we have a next smallest number */
func (this *BSTIterator) HasNext() bool {
    if this.size > 0 {
        return true
    }else {
        return false
    }
}


/**
 * Your BSTIterator object will be instantiated and called as such:
 * obj := Constructor(root);
 * param_1 := obj.Next();
 * param_2 := obj.HasNext();
 */
