import java.util.HashMap;

class Solution {
    public int thirdMax(int[] nums) {
    
        if (nums.length < 3) {
            return this.max(nums);        
        }
        int[] ret = new int[3];
        
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            map.put(nums[i], i);
        }
        int[] newnums = new int[map.size()];
        int index = 0;
        for (int i : map.keySet()) {
            newnums[index] = i;
            index++;
        }
        if (newnums.length < 3) {
            return this.max(newnums);        
        }        
        ret[0] = newnums[0];
        ret[1] = newnums[1];
        ret[2] = newnums[2];

        for (int i = 3; i < newnums.length; i++) {
            index = findmin(ret);
            if (newnums[i] > ret[index]) {
                ret[index] = newnums[i];
            }
        }
        index = findmin(ret);
        return ret[index];
    }
    
    public int max(int[] nums) {
        if (nums.length == 1) {
            return nums[0];
        }
        if (nums[0] < nums[1]) {
            return nums[1];
        } else {
            return nums[0];
        }
    }
    public int findmin(int[] nums) {
        if (nums[0] > nums[1]) {
            if (nums[1] > nums[2]) {
                return 2;
            } else {
                return 1;
            }
        } else {
            if (nums[0] > nums[2]) {
                return 2;
            } else {
                return 0;
            }
        }
    }
    
    
}
