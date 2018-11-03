class Solution:
    def imageSmoother(self, M):
        """
        :type M: List[List[int]]
        :rtype: List[List[int]]
        """
        if not M:
            return M
        m, n = len(M[0]), len(M)
        ret = [[0]*m for i in range(n)]
        
        for i in range(m):
            for j in range(n):
                neighbors = [M[a][b] for a in [j-1, j, j+1] for b in [i-1, i, i+1] if 0 <= a < n and 0 <= b < m]
                ret[j][i] = sum(neighbors) // len(neighbors)
            
        return ret

                    
        
