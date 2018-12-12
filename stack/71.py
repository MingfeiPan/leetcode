class Solution:
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        arr = path.split('/')
        stack = []
        for s in arr:
            if s is '' or s == '.':
                continue
            if s == '..':
                try:
                    stack.pop()
                except IndexError:
                    continue
            else:
                stack.append(s)
                
        if len(stack) == 0:
            return '/'
        ret = ''
        while len(stack) > 0:
            ret = '/' + stack.pop() + ret
        return ret
                
        
