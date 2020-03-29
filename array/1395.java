class Solution {
    
    private int ret = 0;
    public int numTeams(int[] rating) {
        for (int i = 0; i < rating.length-2; i++) {
            dfsUpper(rating, 3, i);
            dfsLower(rating, 3, i);   
        }
        return this.getRet();
    }
    
    public void setRet(int ret) {
        this.ret = ret;
    }
    
    public int getRet() {
        return this.ret;
    }
    
    public void dfsUpper(int[] rating, int left, int start) {
        if (left == 1) {
            this.setRet(this.getRet()+1);
            return;
        }
        for (int i = start; i < rating.length; i++) {
            if (rating[start] < rating[i]) {
                dfsUpper(rating, left-1, i);
            }
        }
    }
    
    public void dfsLower(int[] rating, int left, int start) {
        if (left == 1) {
            this.setRet(this.getRet()+1);
            return;
        }
        for (int i = start+1; i < rating.length; i++) {
            if (rating[start] > rating[i]) {
                dfsLower(rating, left-1, i);
            }
        }        
    }
}
