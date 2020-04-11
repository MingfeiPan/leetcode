import java.util.List;
import java.util.ArrayList;

class MinStack {

    private List<Integer> main;
    private List<Integer> min;
    /** initialize your data structure here. */
    public MinStack() {
        this.main = new ArrayList<Integer>();
        this.min = new ArrayList<Integer>();
    }
    
    public void push(int x) {
        this.main.add(x);
        if (this.min.size() == 0 || x <= this.min.get(this.min.size()-1)) {
            this.min.add(x);
        }
    }
    
    public void pop() {
        if (this.min.get(this.min.size()-1).equals(this.main.get(this.main.size()-1))) {
            this.min.remove(this.min.size()-1);
        }
        this.main.remove(this.main.size()-1);
    }
    
    public int top() {
        return this.main.get(this.main.size()-1);
    }
    
    public int getMin() {
        if (this.min.size() == 0) {
            return 0;
        }
        return this.min.get(this.min.size()-1);
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
