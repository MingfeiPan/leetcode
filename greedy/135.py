class Solution:
    def candy(self, ratings):
        """
        :type ratings: List[int]
        :rtype: int
        """
        
        ret = list(itertools.repeat(1, len(ratings)))
        for i in range(1, len(ratings)):
            #由左向右 如果右比左大 则ret右为ret左+1
            if ratings[i] > ratings[i-1]:
                ret[i] = ret[i-1] + 1
        for i in range(len(ratings)-1, 0, -1):
            #由右向左 如果左比右大 且ret右比ret左大 则ret左为ret右+1
            if ratings[i] < ratings[i-1] and ret[i-1] <= ret[i]:
                ret[i-1] = ret[i] + 1
                
        return sum(ret)
            
        
        
