class Solution:
    def checkRecord(self, s: str) -> bool:
        if not s:
            return True
        
        flag = 0
        flag1 = 0
        
        for i in range(len(s)):
            if s[i] == 'A':
                flag += 1
                if flag > 1:
                    return False
            if s[i] == 'L':
                if i - 1 >= 0 and s[i-1] == 'L' and i + 1 < len(s) and s[i+1] == 'L':
                    return False
                
        return True
                
        
                    
