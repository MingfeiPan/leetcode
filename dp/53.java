class Solution {
    public int maxSubArray(int[] nums) {
        int ret = Integer.MIN_VALUE;
        int cur = 0;
        for (int i : nums) {
            if (cur < 0) {
                cur = i;
            } else {
                cur += i;
            }
            if (ret < cur) {
                ret = cur;
            }
        }
        return ret;
    }
}
