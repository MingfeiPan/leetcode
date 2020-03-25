import java.util.Map;
import java.util.HashMap;

class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        Map<Integer, Integer> countMap = new HashMap<>();
        for (int i : arr) {
            if (countMap.get(i) == null) {
                countMap.put(i, 1);
            } else {
                countMap.put(i, countMap.get(i)+1);
            }
        }
        Map<Integer, Boolean> occuMap = new HashMap<>();
        for (Map.Entry<Integer, Integer> entry : countMap.entrySet()) {
            int value = entry.getValue();
            if (occuMap.get(value) != null) {
                return false;
            }
            occuMap.put(value, true);
        }
        return true;
    }
}
