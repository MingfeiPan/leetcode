import java.util.*;

class Solution {
    public int findLucky(int[] arr) {
        int ret = -1;
        Map<Integer, Integer> map = new HashMap<>();
        for (int i : arr) {
            if (map.get(i) == null) {
                map.put(i, 1);
            }else {
                map.put(i, map.get(i)+1);
            }
        }
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            if (entry.getKey() == entry.getValue()) {
                if (entry.getKey() > ret) {
                    ret = entry.getKey();
                }
            }
        }
        return ret;
    }
}
