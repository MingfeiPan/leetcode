class Solution:
    def isLongPressedName(self, name: str, typed: str) -> bool:
        cur = tar = 0
        pre = name[0]
        
        while cur < len(name):
            if tar >= len(typed):
                return False
            if name[cur] == typed[tar]:
                pre = name[cur]
                cur += 1
                tar += 1
            else:
                if typed[tar] ==  pre:
                    tar += 1
                    continue
                else:
                    return False
                
        return True
                
            
