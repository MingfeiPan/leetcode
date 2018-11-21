#TLE

class Solution:
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        
        ret = - sys.maxsize
        
        for i in range(len(nums)):
            j = i + 1
            temp = nums[i]
            ret = temp if temp > ret else ret
            while j < len(nums):
                temp *= nums[j]
                ret = temp if temp > ret else ret
                j += 1
        return ret
 
# not TLE ...               
int maxProduct(int* nums, int numsSize) {
    if(numsSize == 0){
        return 0;
    }
    int ret = INT_MIN;
    int temp;
    for(int i = 0; i < numsSize; i++){
        int j = i + 1;
        temp = nums[i];
        ret = ret > temp ? ret : temp;
        while(j < numsSize){
            temp *= nums[j++];
            ret = ret > temp ? ret : temp;
        }
    }
    return ret;
    
    
}
