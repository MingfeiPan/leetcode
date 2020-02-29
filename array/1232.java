class Solution {
    public boolean checkStraightLine(int[][] coordinates) {
        if (coordinates.length <= 2) {
            return true;
        }
        
        int value0 = coordinates[1][0] - coordinates[0][0];
        int value1 = coordinates[1][1] - coordinates[0][1];
        for (int i = 1; i < coordinates.length-1; i++) {
            if (value0*(coordinates[i+1][1] - coordinates[i][1]) != value1*(coordinates[i+1][0] - coordinates[i][0])) {
                return false;
            }
        }
        return true;
    }
    
}
