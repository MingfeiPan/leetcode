class StockSpanner:

    def __init__(self):
        self.stack = []

    def next(self, price):
        """
        :type price: int
        :rtype: int
        """
        ret = 1
        while len(self.stack) > 0 and self.stack[-1][0] <= price:
            ret += self.stack.pop()[1]
        self.stack.append([price, ret])
        return ret
            
            
        


# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)
