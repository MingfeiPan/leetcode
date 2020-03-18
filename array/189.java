class Solution {
    public void rotate(int[] nums, int k) {
        if (k > nums.length) {
            k = k % nums.length;
        }
        // use reverse
        // reverse all
        reverse(nums, 0, nums.length-1);
        // reverse first k
        reverse(nums, 0, k-1);
        // reverse last n-k
        reverse(nums, k, nums.length-1);
    }
    
    public void reverse(int[] nums, int start, int end) {
        int temp;
        for (int i = start, j = end; i < j; i++, j--) {
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }
}
