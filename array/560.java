class Solution {
    public int subarraySum(int[] nums, int k) {
        int ret = 0;
        for (int i = 0; i < nums.length; i++) {
            int cur = nums[i];
            if (cur == k) {
                ret++;
            }
            for (int j = i+1; j < nums.length; j++) {
                cur += nums[j];
                if (cur == k) {
                    ret++;
                }
            }
        }
        return ret;
    }
}
