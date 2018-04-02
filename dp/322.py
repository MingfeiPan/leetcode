class Solution:
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        
        #初始化时, 使数组中预估数量都比最终数额大一, 也就是一个超过可能情况最大值的一个数量, 这样可以再无法组合的情况时用于判断返回-1
        ret = [amount+1 for i in range(0, amount+1)]
        for i in range(0, amount+1):
            if i == 0:
                ret[i] = 0
            else:
                for coin in coins:
                    if i >= coin:
                        ret[i] = min(ret[i-coin] + 1, ret[i])

        if ret[amount] == amount+1:
            return -1
        return ret[amount]        
