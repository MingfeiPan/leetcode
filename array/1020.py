class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        
        if not sum(A) % 3 == 0:
            return False
        target = sum(A) / 3
        
        index = 0
        curr = 0
        
        for i in A:
            curr += i
            if curr == target:
                curr = 0
                
        return not curr
                

            
            
        
        
