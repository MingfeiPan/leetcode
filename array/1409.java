import java.util.*;
class Solution {
    public int[] processQueries(int[] queries, int m) {
        int[] ret = new int[queries.length];
        LinkedList<Integer> p = new LinkedList<>();
        for (int i = 1; i <= m; i++) {
            p.add(i);
        }
        
        for (int i = 0; i < queries.length; i++) {
            int pos = queries[i];
            System.out.println(p);
            ret[i] = p.indexOf(pos);
            p.removeFirstOccurrence(pos);
            p.addFirst(pos);
        }
        return ret;
    }
}
