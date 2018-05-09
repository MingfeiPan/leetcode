class Solution:
    def largeGroupPositions(self, S):
        """
        :type S: str
        :rtype: List[List[int]]
        """
        ret = []
        start = 0
        count = 1
        c = S[0]
        for i in range(1, len(S)):
            if S[i] == S[i-1]:
                count += 1
            else:
                if count >= 3:
                    ret.append([start, start+count-1])
                    start = i
                    count = 1
                else:
                    start = i
                    count = 1
        
        if count >= 3:
            ret.append([start, start+count-1])
        return ret
                
