// sort
import java.util.*;

class Solution {
    
    private Map<Integer, Integer> map = new HashMap<>();
    
    public int getKth(int lo, int hi, int k) {

        for (int index = 1; index <= hi; index++) {
            int power = 0;
            int i = index;
            while (i != 1) {
                if (this.map.containsKey(i)) {
                    power += this.map.get(i);
                    break;
                }else {
                    if (i % 2 == 0) {
                        i = i / 2;
                    } else {
                        i = 3 * i + 1;
                    }
                    power++;
                }
            }
            this.map.put(index, power);
        }
        List<Item> list = new ArrayList<>();
        
        for (int i = lo; i <= hi; i++) {
            Item item = new Item();
            item.value = i;
            item.power = this.map.get(i);
            list.add(item);
        }
        list.sort(new Comparator<Item>(){
            public int compare(Item i1, Item i2) {
                if (i1.power == i2.power) {
                    return i1.value - i2.value;
                } else {
                    return i1.power - i2.power;
                }
            }
        });
        return list.get(k-1).value;
    }
    
    public static class Item{
        public Integer value;
        public Integer power;
    }
    
}

// heap
import java.util.*;

class Solution {
    
    private Map<Integer, Integer> map = new HashMap<>();
    
    public int getKth(int lo, int hi, int k) {

        for (int index = 1; index <= hi; index++) {
            int power = 0;
            int i = index;
            while (i != 1) {
                if (this.map.get(i) != null) {
                    power += this.map.get(i);
                    break;
                }else {
                    if (i % 2 == 0) {
                        i = i / 2;
                    } else {
                        i = 3 * i + 1;
                    }
                    power++;
                }
            }
            this.map.put(index, power);
        }

        PriorityQueue<Item> pq = new PriorityQueue(new Comparator<Item>(){
            public int compare(Item i1, Item i2) {
                if (i1.power == i2.power) {
                    return i2.value - i1.value;
                }
                return i2.power - i1.power;
            }
        });        
        for (int i = lo; i <= hi; i++) {
            Item item = new Item();
            item.value = i;
            item.power = this.map.get(i);
            pq.offer(item);
        }
        while (pq.size() > k) {
            Item item = pq.poll();
        }
        return pq.peek().value;
    }
    
    public static class Item{
        public Integer value = 0;
        public Integer power = 0;
    }
    
}
