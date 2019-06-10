#math solution
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        return sum(set(nums))*2 - sum(nums)


#xor solution, 注意xor的性质 1 ^ 1 = 0, 1 ^ 0 = 1
import functools
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        return functools.reduce(lambda a, b: a ^ b, nums)
