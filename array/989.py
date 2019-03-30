class Solution:
    def addToArrayForm(self, A: List[int], K: int) -> List[int]:
        
        num = int(''.join(str(x) for x in A)) + K
        
        return ([int(x) for x in str(num)])
        
                
            
