#backtracking
class Solution:
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        ret = []
        candidates.sort()
        self.backtrack(ret, [], candidates, target, 0)
        return ret
    
    def backtrack(self, ret, temp, candidates, value, start):
        if value < 0:
            return
        elif value == 0:
            ret.append(temp)
            return
        else:
            for i in range(start, len(candidates)):
                self.backtrack(ret, temp + [candidates[i]], candidates, value - candidates[i], i)
                
    
        
