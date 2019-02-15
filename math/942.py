class Solution:
    def diStringMatch(self, S: 'str') -> 'List[int]':
        ret = []
        left = 0
        right = len(S)
        for i in range(0, len(S)):
            if S[i] == 'I':
                ret.append(left)
                left += 1
            else:
                ret.append(right)
                right -= 1
        ret.append(left)
        
        return ret
