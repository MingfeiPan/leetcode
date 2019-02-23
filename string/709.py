class Solution:
    def toLowerCase(self, str: str) -> str:
        ret = []
        for c in str:
            if 65 <= ord(c) <= 90:
                ret.append(chr(ord(c)+32))
            else:
                ret.append(c)
        return ''.join(ret)
