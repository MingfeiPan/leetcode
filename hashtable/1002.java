import java.util.*;
class Solution {
    public List<String> commonChars(String[] A) {
        List<String> ret = new ArrayList<>();
        List<Map<String, Integer>> list = new ArrayList<>();
        for (String s : A) {
            Map<String, Integer> map = new HashMap<>();
            for (int i = 0; i < s.length(); i++) {
                String c = String.valueOf(s.charAt(i));
                if (map.containsKey(c)) {
                    map.put(c, map.get(c) + 1);
                } else {
                    map.put(c, 1);
                }
            }
            list.add(map);
        }
        Map<String, Integer> targetMap = list.get(0);
        for (Map.Entry<String, Integer> entry : targetMap.entrySet()) {
            String key = entry.getKey();
            int value = entry.getValue();
            int repeat = value;
            boolean flag = true;
            for (int i = 1; i < list.size(); i++) {
                if (list.get(i).containsKey(key)) {
                    repeat = Math.min(repeat, list.get(i).get(key));
                } else {
                    flag = false;
                    break;
                }
            }
            while (flag && repeat > 0) {
                ret.add(key);
                repeat--;
            }            
        }
        return ret;
    }
}
