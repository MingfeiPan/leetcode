class Solution {
public:
    int countVowelStrings(int n) {
        int ret = 0;
        recur(ret, 0, 0, n);
        return ret;
    }
private:
    void recur(int& ret, int curindex, int curlength, int& targetlength) {
        if (curlength == targetlength) {
            ret++;
            return;
        }
        for (int i = 0; i < 5; i++) {
            if (i >= curindex) {
                recur(ret, i, curlength+1, targetlength);
            }
        }
    }
};
