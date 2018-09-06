import itertools

class Solution:
    def readBinaryWatch(self, num):
        """
        :type num: int
        :rtype: List[str]
        """
        
        mapper = {
            1:8,
            2:4,
            3:2,
            4:1,
            5:32,
            6:16,
            7:8,
            8:4,
            9:2,
            10:1,
        }
        if num == 0:
            return ['0:00']
        nums = list(itertools.combinations(range(1,11), num))
        ret = []
        for indi in nums:
            hourret = 0
            minret = 0
            for i in indi:
                if i <= 4:
                    hourret += mapper.get(i, 0)
                else:
                    minret += mapper.get(i,0)
            
            if minret > 59 or hourret > 11:
                continue
            if minret >= 10:
                ret.append('{}:{}'.format(hourret, minret))
            else:
                ret.append('{}:0{}'.format(hourret, minret))
                
        return ret
            
        
        
