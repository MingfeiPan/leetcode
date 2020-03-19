class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] ret = new int[nums.length];
        ret[0] = 1;
        
        for (int i = 1; i < nums.length; i++) {
            ret[i] = nums[i-1]*ret[i-1];
        }
        int accu = 1;
        for (int i = nums.length-1; i >= 0; i--) {
            ret[i] *= accu;
            accu *= nums[i];
        }
        return ret;
    }
}
