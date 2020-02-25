import java.util.*;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        int[] ret = new int[2];
        for (int i = 0; i < nums.length; i++) {
            int left = target - nums[i];
            if (map.get(left) != null) {
                ret[0] = map.get(left);
                ret[1] = i;
                break;
            }else {
                map.put(nums[i], i);
            }
        }
        return ret;
    }
}
