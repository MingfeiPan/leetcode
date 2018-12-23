class Solution:
    def decodeString(self, s):
        """
        :type s: str
        :rtype: str
        """
        stack = []
        multi = 0
        ret = ''
        for c in s:
            if c == '[':
                stack.append(ret)
                stack.append(multi)
                ret = ''
                multi = 0
            elif c == ']':
                num = stack.pop()
                temp = stack.pop()
                ret = temp + num*ret
            elif c.isdigit():
                multi = multi*10 + int(c)
            else:
                ret += c
        return ret        
        
