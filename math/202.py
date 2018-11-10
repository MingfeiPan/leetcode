class Solution:
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        sums_set = set()
        
        while True:
            n = sum([int(i) ** 2 for i in str(n)])
            
            if n == 1:
                return True
            elif n in sums_set:
                return False
            else:
                sums_set.add(n)

           
