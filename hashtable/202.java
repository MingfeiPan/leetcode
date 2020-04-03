import java.util.Map;
import java.util.HashMap;

class Solution {
    public boolean isHappy(int n) {
        Map<Integer, Boolean> map = new HashMap<>();
        while (true) {
            n = this.getSum(n);
            if (n == 1) {
                return true;
            }
            if (map.containsKey(n)) {
                return false;
            } else {
                map.put(n, true);
            }
        }
    }
    
    private int getSum(int n) {
        int ret = 0;
        while (n > 0) {
            int i = n % 10;
            n = n / 10;
            ret += i * i;
        }
        return ret;
    }
}
