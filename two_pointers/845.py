class Solution:
    def longestMountain(self, A: List[int]) -> int:
        if not A or len(A) < 3:
            return 0
        
        result = 0
        for i in range(1, len(A)-1):
            total = 1
            if A[i-1] < A[i] and A[i] > A[i+1]:
                pre = i - 1
                nxt = i + 1
                total += 2
                
                while pre > 0 and A[pre] > A[pre-1]:
                    pre -= 1
                    total += 1
                    
                while nxt < (len(A) - 1) and A[nxt] > A[nxt+1]:
                    nxt += 1
                    total += 1
                
                if total > result:
                    result = total
                    
        return result
             
        
