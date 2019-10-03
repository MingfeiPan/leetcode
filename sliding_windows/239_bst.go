import (
	"fmt"
	"math/rand"
	"time"
)

type TreeNode struct {
	val   int
	left  *TreeNode
	right *TreeNode
}

func Init(val int) *TreeNode {
	t := TreeNode{val: val, left: nil, right: nil}
	return &t
}
func (t *TreeNode) Insert(val int) *TreeNode {
	if t == nil {
		return &TreeNode{val: val, left: nil, right: nil}
	}
	if t.val < val {
		t.right = t.right.Insert(val)
	} else {
		t.left = t.left.Insert(val)
	}
	return t
}

func (t *TreeNode) GetMax() *TreeNode {
	if t == nil {
		return nil
	}
	for {
		if t.right == nil {
			return t
		} else {
			t = t.right
		}
	}
}

func (t *TreeNode) GetMin() *TreeNode {
	if t == nil {
		return nil
	}
	for {
		if t.left == nil {
			return t
		} else {
			t = t.left
		}
	}
}

func (t *TreeNode) Delete(val int) *TreeNode {
	if t == nil {
		return t
	}
	if val < t.val {
		t.left = t.left.Delete(val)
	} else if val > t.val {
		t.right = t.right.Delete(val)
	} else {
		// find
		if t.left != nil && t.right != nil {
			rand.Seed(time.Now().UnixNano())
			if rand.Intn(2) == 0 {
				t.val = t.left.GetMax().val
				t.left = t.left.Delete(t.val)
			} else {
				t.val = t.right.GetMin().val
				t.right = t.right.Delete(t.val)
			}
		} else if t.left == nil && t.right == nil {
			t = nil
		} else if t.left == nil {
			t = t.right
		} else {
			t = t.left
		}
	}
	return t
}

func (t *TreeNode) Traversal() {
	if t == nil {
		return
	}
	t.left.Traversal()
	fmt.Printf("%d ", t.val)
	t.right.Traversal()
}

func maxSlidingWindow(nums []int, k int) []int {
    if len(nums) == 0{
        return nil
    }
	t := Init(nums[0])
	ret := make([]int, 0)
	for i := 1; i < k; i++ {
		t = t.Insert(nums[i])
	}
	ret = append(ret, t.GetMax().val)
	for i := 0; i < len(nums)-k; i++ {
		t = t.Delete(nums[i])
		t = t.Insert(nums[i+k])
		ret = append(ret, t.GetMax().val)
	}   
    return ret
}
