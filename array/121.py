class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        ret = 0
        minx = sys.maxsize
        
        for i in prices:
            minx = minx if minx < i else i
            ret = ret if ret > (i - minx) else (i - minx)
        return ret

