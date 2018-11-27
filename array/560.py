#TLE
class Solution:
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        
        ret = 0
        for i in range(len(nums)):
            pre_sum = 0
            for j in range(i, len(nums)):
                pre_sum += nums[j]
                if pre_sum == k:
                    ret += 1
                    
        return ret
        
        

#pass
int subarraySum(int* nums, int numsSize, int k) {
    int ret = 0;
    int sum;
    for(int i = 0; i < numsSize; i++){
        sum = 0;
        for(int j = i; j < numsSize; j++){
            sum += nums[j];
            if(sum == k){
                ret++;
            }
        }
    }
    return ret;
}


