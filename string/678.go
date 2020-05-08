// 准备两个stack, 一个为'(', 一个为'*', 当遇到')'时 pop '('或者 '*', 如果两个stack已经为空
// 则不匹配 可以return false
// 当检索完整个string后 检查两个stack, 如果还有剩余则依次pop, 注意pop出的index, 如果'('的index比'*'的大, 则这个'('无法匹配到, return false
func checkValidString(s string) bool {
    stack := make([]int, 0)
    stack1 := make([]int, 0)
    for i, c := range s {
        if c == '(' {
            stack = append(stack, i)
        }else if c == '*' {
            stack1 = append(stack1, i)
        }else {
            // find ')'
            if len(stack) != 0 {
                stack = stack[:len(stack)-1]
            }else if len(stack1) != 0 {
                stack1 = stack1[:len(stack1)-1]
            }else {
                return false
            }
        }
    }
    for len(stack) != 0 && len(stack1) != 0 {
        index := stack[len(stack)-1]
        stack = stack[:len(stack)-1]
        index1 := stack1[len(stack1)-1]
        stack1 = stack1[:len(stack1)-1]
        // 如果'(' 出现在'*' 后面 return false
        if index > index1 {
            return false
        }
    }
    // 如果还剩余 '(', return false
    if len(stack) > 0 {
        return false
    }
    return true
}
