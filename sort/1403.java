class Solution {
    public List<Integer> minSubsequence(int[] nums) {
        Arrays.sort(nums);
        int half = this.halfSum(nums);
        List<Integer> ret = new ArrayList<>();
        for (int i = nums.length-1; i >= 0; i--) {
            if (half >= 0) {
                half -= nums[i];
                ret.add(nums[i]);
            }
        }
        return ret;
    }
    
    public int halfSum(int[] nums) {
        int ret = 0;
        for (int i : nums) {
            ret += i;
        }
        return ret/2;
    }
}
