class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        l = [0]
        for i in range(1, len(prices)):
            l.append(max(0, l[i-1] + prices[i] - prices[i-1]))
            
        return max(l)
