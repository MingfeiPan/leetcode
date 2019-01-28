class Solution:
    def minFlipsMonoIncr(self, S):
        """
        :type S: str
        :rtype: int
        """
        count0 = S.count('0')
        count1 = 0
        ret = len(S) - count0 
        for i in range(len(S)):
            if S[i] == '0':
                count0 -= 1
            else:
                ret = min(ret, count0+count1)
                count1 += 1
        return ret

        
