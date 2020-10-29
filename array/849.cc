class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int begin = -1, end = 0, ret = 0, cur = 0;
        for (int i = 0; i < seats.size(); ++i) {
            if (seats[i] == 1) {
                begin = i;
            } else {
                end = begin+1;
                while (end < seats.size() && seats[end] == 0)
                    end++;
                if (begin == -1 || end == seats.size()) {
                    ret = max(ret, end-begin-1);
                } else {
                    if ((end+1-begin) % 2 == 0) {
                        ret = max(ret, (end+1-begin)/2-1); 
                    } else {
                        ret = max(ret, (end+1-begin)/2);     
                    }   
                }
                begin = end;
                i = end;
                
            }
        }
        return ret;
    }
};
