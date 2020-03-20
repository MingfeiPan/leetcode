class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int ret = 0;
        int cur = 0;
        boolean flag = true;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 1) {
                if (flag) {
                    cur++;
                } else {
                    cur = 1;
                    flag = true;
                }
            } else {
                if (flag) {
                    if (cur > ret) {
                        ret = cur;
                    }
                    flag = false;
                }
            }
        }
        if (cur > ret) {
            ret = cur;
        }
        return ret;
    }
}
