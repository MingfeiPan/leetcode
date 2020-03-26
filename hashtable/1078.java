import java.util.*;
class Solution {
    public String[] findOcurrences(String text, String first, String second) {
        String[] strList = text.split(" ");
        Map<String, List<String>> map = new HashMap<>();
        for (int i = 0; i < strList.length-2; i++) {
            String target = strList[i]+strList[i+1];
            if (map.get(target) == null) {
                List<String> cur = new ArrayList<>();
                cur.add(strList[i+2]);
                map.put(target, cur);
            } else {
                List<String> cur = map.get(target);
                cur.add(strList[i+2]);
            }
        }
        List<String> retList = map.get(first+second);
        
        if (retList == null){
            String[] ret = new String[0];
            return ret;
        }
        String[] ret = new String[retList.size()];
        for (int i = 0; i < ret.length; i++) {
            ret[i] = retList.get(i);
        }
        return ret;
    }
}
