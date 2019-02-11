class Solution:
    def largestTimeFromDigits(self, A: 'List[int]') -> 'str':
        ret = ()
        for l in itertools.permutations(A):
            if (l[0] < 2 or (l[0] == 2 and l[1] < 4)) and l[2] < 6 :
                ret = l if l > ret else ret
                
        if ret:
            return '{}{}:{}{}'.format(ret[0],ret[1],ret[2],ret[3])
        
        return ''
