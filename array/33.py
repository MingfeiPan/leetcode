class Solution:
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        
        if not nums:
            return -1
        
        lo = 0
        hi = len(nums) - 1
        while lo < hi:
            mid = int((lo + hi) / 2)
            if nums[hi] < nums[mid]:
                lo = mid + 1
            else:
                hi = mid
                
        index = lo
        lo = 0
        hi = len(nums) - 1
        
        while lo <= hi:
            mid = int((lo + hi) / 2)
            pivot = (mid + index) % len(nums)
            if nums[pivot] == target:
                return pivot
            elif nums[pivot] < target:
                lo = mid + 1
            else:
                hi = mid - 1
        return -1


class Solution:
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        
        if not nums:
            return -1
        low = 0
        high = len(nums) - 1
        while low <= high:                
            mid = (low+high) // 2
            if target == nums[mid]:
                return mid         
            elif nums[mid] >= nums[low]:
                if nums[low] <= target < nums[mid]:  
                    high = mid - 1
                else:
                    low = mid + 1
            elif nums[mid] <= nums[high]:
                if nums[mid] < target <= nums[high]:
                    low = mid + 1
                else:
                    high = mid - 1
        return -1
