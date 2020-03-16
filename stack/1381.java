import java.util.*;

class CustomStack {
    
    private List<Integer> list;
    private int maxSize;
    private int curSize;
    
    public CustomStack(int maxSize) {
        this.maxSize = maxSize;
        this.curSize = 0;
        this.list = new ArrayList<>();
    }
    
    public void push(int x) {
        if (this.curSize == this.maxSize) {
            return;
        }
        this.list.add(x);
        this.curSize++;
    }
    
    public int pop() {
        if (this.curSize == 0) {
            return -1;
        }
        int ret = this.list.remove(this.curSize-1);
        this.curSize--;
        return ret;
    }
    
    public void increment(int k, int val) {
        if (this.curSize < k) {
            k = this.curSize;
        }
        for (int i = 0; i < k; i++) {
            this.list.set(i, this.list.get(i)+val);
        }
    }
}

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack obj = new CustomStack(maxSize);
 * obj.push(x);
 * int param_2 = obj.pop();
 * obj.increment(k,val);
 */
