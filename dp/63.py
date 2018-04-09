#很直白的思路,  但是为了不用额外的空间, 代码写的就比较丑了, 因为这里1已经表示有障碍, 所以用2表示初始化的可通行,然后再结果出除一下就是真实个数了, 另外就是每个格子除了判断来路两个方向之外, 还要判断自己本身是否有障碍
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        for i in range(0,len(obstacleGrid)):
            for j in range(0,len(obstacleGrid[i])):
                if i == 0 and j == 0:
                    if obstacleGrid[i][j] != 1:
                        obstacleGrid[i][j] = 2 
                elif i == 0 and j != 0:
                    if obstacleGrid[i][j] != 1:
                        if obstacleGrid[i][j-1] == 1:
                            obstacleGrid[i][j] = 1
                        else:
                            obstacleGrid[i][j] = 2
                elif i != 0 and j == 0:
                    if obstacleGrid[i][j] != 1:
                        if obstacleGrid[i-1][j] == 1:
                            obstacleGrid[i][j] = 1
                        else:
                            obstacleGrid[i][j] = 2
                elif obstacleGrid[i][j] != 1:
                    if obstacleGrid[i-1][j] == 1:
                        obstacleGrid[i][j] = obstacleGrid[i][j-1]
                    elif obstacleGrid[i][j-1] == 1:
                        obstacleGrid[i][j] = obstacleGrid[i-1][j]
                    else:
                        obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1]
        if obstacleGrid[i][j] == 1:
            return 0
        else:
            return int(obstacleGrid[i][j] / 2)
                        
        
