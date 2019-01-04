class Solution:
    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """
        stack = []
        
        for c in tokens:
            
            if c == '+':
                temp = stack.pop()
                temp1 = stack.pop()
                stack.append(temp+temp1)
            elif c =='-':
                temp = stack.pop()
                temp1 = stack.pop()
                stack.append(temp1 - temp)
            elif c == '*':
                temp = stack.pop()
                temp1 = stack.pop()
                stack.append(temp*temp1)                
            elif c == '/':
                temp = stack.pop()
                temp1 = stack.pop()
                stack.append(int(temp1 / temp))     
            else:
                stack.append(int(c))
                
                
        return stack.pop()
            
