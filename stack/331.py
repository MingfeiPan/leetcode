class Solution:
    def isValidSerialization(self, preorder):
        """
        :type preorder: str
        :rtype: bool
        """
        arr_pre_order = preorder.split(',')
        
        stack = []
        for node in arr_pre_order:
            stack.append(node)
            while len(stack) > 1 and stack[-1] == '#' and stack[-2] == '#':
                stack.pop()
                stack.pop()
                if len(stack) < 1:
                    return False
                stack[-1] = '#'
                
        if len(stack) == 1 and stack[0] == '#':
            return True
        return False
