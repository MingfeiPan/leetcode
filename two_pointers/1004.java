class Solution {
    public int longestOnes(int[] A, int K) {
        int ret = 0, start = 0, count = 0;
        for (int end = 0; end < A.length; end++) {
            if (A[end] == 0) {
                count++;
            }
            if (count > K) {
                if (A[start] == 0) {
                    count--;
                }
                start++;
            }            
            if (end - start + 1 > ret) {
                ret = end - start + 1;
            }
        }
        return ret;
    }
}
