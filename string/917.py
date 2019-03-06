class Solution:
    def reverseOnlyLetters(self, S: str) -> str:
        pre = 0
        nxt = len(S) - 1
        
        prelist = []
        nxtlist = []
        
        def is_good(c):
            return c.isalpha()
            # return 65 <= ord(c) <= 90 or 97 <= ord(c) <= 122
        
        while pre < nxt:
            
            while pre < nxt and not is_good(S[pre]):
                prelist.append(S[pre])
                pre += 1
                
            while pre < nxt and not is_good(S[nxt]):
                nxtlist.append(S[nxt])
                nxt -= 1
                
            if pre >= nxt:
                break
            prelist.append(S[nxt])
            nxt -= 1
            nxtlist.append(S[pre])
            pre += 1
            
        if pre == nxt:
            prelist.append(S[pre])
        nxtlist.reverse()
        return ''.join(prelist)+''.join(nxtlist)
            
