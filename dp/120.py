# 使用滚动数组可以保证到O(n)的空间复杂度, 每一层加出来的结果存一个数组即可
class Solution:
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        ret = []
        ret1 = []
        i = 0
        for line in triangle:
            if i == 0:
                for key in range(0, len(line)):
                    ret.append(line[key])
                ret1 = []
                i += 1
                continue
            elif i % 2 == 1:
                for key in range(0, len(line)):
                    if key == 0:
                        ret1.append(ret[key] + line[key])
                    elif key == len(line) - 1:
                        ret1.append(ret[key-1] + line[key])
                    else:
                        ret1.append(min(ret[key] + line[key], ret[key-1] + line[key]))
                ret = []
                i += 1
                continue
            elif i % 2 == 0:
                for key in range(0, len(line)):
                    if key == 0:
                        ret.append(ret1[key] + line[key])
                    elif key == len(line) - 1:
                        ret.append(ret1[key-1] + line[key])
                    else:
                        ret.append(min(ret1[key] + line[key], ret1[key-1] + line[key]))
                ret1 = []    
                i += 1
            
        if ret:
            return min(ret)
        else:
            return min(ret1)
            
                
                
#better
class Solution:
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        dp = copy.copy(triangle[-1])
        depth = len(triangle) - 1
        while depth > 0:
            for i in range(len(triangle[depth-1])):
                dp[i] = min(dp[i] + triangle[depth-1][i], dp[i+1] + triangle[depth-1][i])
            depth -= 1
                
        return dp[0]
                
        
        
