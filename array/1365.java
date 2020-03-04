class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int[] ret = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            int cur = i;
            for (int j = 0; j < nums.length; j++) {
                if (j != i && nums[j] < nums[i]) {
                    ret[cur]++;
                }
            }
        }
        return ret;
    }
}

class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int[] ret = new int[nums.length];
        int[] count = new int[101];
        for (int i : nums) {
            count[i]++;
        }
        // 对count做累加
        for (int i = 1; i < count.length; i++) {
            count[i] += count[i-1];
        }
        
        for (int i = 0; i < ret.length; i++) {
            if (nums[i] == 0) {
                ret[i] = 0;
            }else {
                ret[i] = count[nums[i]-1];    
            }
        }
        return ret;
    }
}
