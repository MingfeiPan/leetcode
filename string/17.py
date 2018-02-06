#每次用前一序列的所有结果, 与最后一次的结果做拼接
class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        mapper = {"2":"abc", "3":"def", "4":"ghi", "5":"jkl", "6":"mno", "7":"qprs", "8":"tuv", "9":"wxyz"}
        if len(digits) == 0:
            return []
        if len(digits) == 1:
            return list(mapper[digits[0]])
        
        pre = self.letterCombinations(digits[:-1])
        now = mapper[digits[-1]]
        return [i + j for i in pre for j in now]
         
    
        
