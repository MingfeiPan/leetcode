class Solution {
    public int pivotIndex(int[] nums) {
        if (nums.length <= 2) {
            return -1;
        }
        int leftsum = 0;
        int rightsum = 0;
        
        for (int i = 1; i < nums.length; i++) {
            rightsum += nums[i];
        }
        for (int i = 0; i < nums.length; i++) {
            if (leftsum == rightsum) {
                return i;
            }else {
                leftsum += nums[i];
                if (i < nums.length-1) {
                    rightsum -= nums[i+1];    
                }
            }
        }
        return -1;
    }
}
