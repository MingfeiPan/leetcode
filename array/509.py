class Solution:
    def fib(self, N):
        """
        :type N: int
        :rtype: int
        """
        return self.fib_recur(N, 0, 1)
    
    def fib_recur(self, N, arg0, arg1):
        if N == 0:
            return arg0
        return self.fib_recur(N-1, arg1, arg0+arg1)
