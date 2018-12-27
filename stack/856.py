class Solution:
    def scoreOfParentheses(self, S):
        """
        :type S: str
        :rtype: int
        """
        
        stack = [0]
        for c in S:
            if c == '(':
                stack.append(0)
            else:
                temp = stack.pop()
                if temp == 0:
                    ret = 1
                else:
                    ret = temp * 2
                stack[-1] += ret
        return stack[0]
