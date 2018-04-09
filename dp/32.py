class Solution:
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        matrix = [0]*(len(s))
        for i in range(1, len(s)):
            if s[i] == ')':
                if s[i-1] == '(':
                    if i > 1:
                        matrix[i] = matrix[i-2] + 2
                    else:
                        matrix[i] = 2
                elif i - matrix[i-1] > 0 and s[i-matrix[i-1]-1] == '(':
                    if i - matrix[i-1] - 2 >= 0:
                        matrix[i] = matrix[i-1] + matrix[i-matrix[i-1]-2] + 2
                    else:
                        matrix[i] = matrix[i-1] + 2
        if len(matrix):
            return max(matrix)
        return 0            

