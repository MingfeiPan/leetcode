class Solution {
    public int[] createTargetArray(int[] nums, int[] index) {
        int[] ret = new int[nums.length];
        // update index 
        for (int i = 1; i < index.length; i++) {
            for (int j = 0; j < i; j++) {
                // 每一个在当前i 左边的数字, 如果比当前i大, 说明在i插入的时候需要移动
                if (index[j] >= index[i]) {
                    index[j]++;
                }
            }
        }
        for (int i = 0; i < index.length; i++) {
            ret[index[i]] = nums[i];
        }
        return ret;
    }
}
