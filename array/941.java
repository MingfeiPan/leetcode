class Solution {
    public boolean validMountainArray(int[] A) {
        if (A.length < 3) {
            return false;
        }
        int pivot = 0;
        boolean inc = false;
        for (int i = 0; i < A.length-1; i++) {
            if (A[i] < A[i+1]) {
                inc = true;
            } else {
                pivot = i;
                break;
            }
        }
        for (int i = pivot; i < A.length-1; i++) {
            if (A[i] <= A[i+1]) {
                return false;
            }
        }
        if (!inc) {
            return false;
        }
        return true;
    }
}
