import java.util.*;

class Solution {
    public List<Integer> luckyNumbers (int[][] matrix) {
        List<Integer> ret = new ArrayList<>(); 
        for (int i = 0; i < matrix.length; i++) {
            //find minimum first
            int minimum = matrix[i][0];
            int minimumIndex = 0;
            for (int j = 0; j < matrix[0].length; j++) {
                if (matrix[i][j] < minimum) {
                    minimum = matrix[i][j];
                    minimumIndex = j;
                }
            }
            // check maximum
            int maximum = matrix[0][minimumIndex];
            for (int k = 1; k < matrix.length; k++) {
                if (matrix[k][minimumIndex] > maximum) {
                    maximum = matrix[k][minimumIndex];
                }
            }
            if (maximum == minimum) {
                ret.add(maximum);
            }
        }
        return ret;
    }
}
