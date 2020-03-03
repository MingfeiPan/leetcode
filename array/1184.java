class Solution {
    public int distanceBetweenBusStops(int[] distance, int start, int destination) {
        int cd = 0;
        int ccd = 0;
        if (start > destination) {
            int temp = destination;
            destination = start;
            start = temp;
        }
        for (int i = 0; i < distance.length; i++) {
            if (start <= i && destination > i) {
                cd += distance[i];
            }else {
                ccd += distance[i];
            }
        }
        if (cd < ccd) {
            return cd;
        }
        return ccd;
    }
}
