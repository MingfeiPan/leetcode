import java.util.Map;
import java.util.HashMap;

class Solution {
    public int countElements(int[] arr) {
        int ret = 0;
        Map<Integer, Integer> map = new HashMap<>();
        for (int num : arr) {
            if (map.containsKey(num)) {
                map.put(num, map.get(num)+1);
            }else {
                map.put(num, 1);
            }
        }
        for (int key : map.keySet()) {
            if (map.containsKey(key+1)) {
                ret += map.get(key);
            }
        }
        return ret;
    }
}
