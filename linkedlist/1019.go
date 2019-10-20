/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

// 用一个stack, 保存每一个结果的index, 然后做检查
// 如果下一个值比这个下标的值大, 那就可以替换掉当前结果里的值
// 还可以一路 pop stack检索里面存的值是否都可以替换
// 直到比当前值大, 最终再检索一次stack, 把留下的没有next greater的index的值写成0
// 坏处是要检索cur node之前的值, 所以链表要先转成数组

func nextLargerNodes(head *ListNode) []int {
    ret := make([]int, 0)
    for head != nil {
        ret = append(ret, head.Val)
        head = head.Next
    }
    stack := make([]int, 0)
    index := 0
    for index < len(ret) {
        for len(stack) > 0 && ret[stack[len(stack)-1]] < ret[index] {
            ret[stack[len(stack)-1]] = ret[index]
            stack = stack[:len(stack)-1]
        }
        stack = append(stack, index)
        index++
    }
    for len(stack) > 0 {
        ret[stack[len(stack)-1]] = 0
        stack = stack[:len(stack)-1]
    }
    return ret
    
}
