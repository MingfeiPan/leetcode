class Solution:
    def letterCasePermutation(self, S):
        """
        :type S: str
        :rtype: List[str]
        """
        ret = []
        self.dfs(ret, '', 0, S)
        return ret
        
    def dfs(self, ret, temp, index, S):
        if len(temp) == len(S):
            ret.append(temp)
            return
        
        if not S[index].isdigit():
            if S[index].islower():
                # self.dfs(ret, temp+S[index], index+1, S)
                self.dfs(ret, temp+S[index].upper(), index+1, S)
            else:
                # self.dfs(ret, temp+S[index], index+1, S)
                self.dfs(ret, temp+S[index].lower(), index+1, S)
            
        self.dfs(ret, temp+S[index], index+1, S)
