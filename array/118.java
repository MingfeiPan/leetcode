import java.util.*;

class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> ret = new ArrayList<>();
        for (int index = 1; index <= numRows; index++) {
            List<Integer> curList = new ArrayList<>();
            curList.add(1);
            if (index == 1) {
                ret.add(curList);
                continue;
            }
            if (index == 2) {
                curList.add(1);
                ret.add(curList);
                continue;
            }
            for (int i = 1; i < index-1; i++) {
                curList.add(ret.get(index-2).get(i-1) + ret.get(index-2).get(i));
            }
            curList.add(1);
            ret.add(curList);
        }
        return ret;
    }
}
