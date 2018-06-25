class Solution:
    def flipAndInvertImage(self, A):
        """
        :type A: List[List[int]]
        :rtype: List[List[int]]
        """
        for arr in A:
            arr.reverse()
            arr[::] = map(lambda a : a ^ 1, arr)
        return A
        # return [[i^1 for i in arr[::-1]] for arr in A]
