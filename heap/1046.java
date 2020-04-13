import java.util.PriorityQueue;

class Solution {
    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(new Comparator<Integer>(){
            public int compare(Integer i1, Integer i2) {
                return i2 - i1;
            }
        });
        for (int i : stones) {
            pq.offer(i);
        }
        while (pq.size() > 1) {
            int a = pq.poll();
            int b = pq.poll();
            if (a < b) {
                pq.offer(b-a);
            }else if (a > b) {
                pq.offer(a-b);
            }
        }
        if (pq.size() == 0) {
            return 0;
        }
        return pq.poll();
    }
}
