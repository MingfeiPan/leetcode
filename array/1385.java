class Solution {
    public int findTheDistanceValue(int[] arr1, int[] arr2, int d) {
        int ret = 0;
        for (int i = 0; i < arr1.length; i++) {
            for (int j = 0; j < arr2.length; j++) {
                if (this.absSub(arr1[i], arr2[j]) <= d) {
                    ret++;
                    break;
                } else {
                }
            }
        }
        return arr1.length - ret;
    }
    
    private int absSub(int i, int j) {
        if (i < j) {
            return j - i;
        }else {
            return i - j;
        }
    }
}
