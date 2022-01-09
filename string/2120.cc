class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int a = 0, b = 0, ret = 0;
        std::vector<int> outs;
        for (int i = 0; i < s.size(); ++i) {
            a = startPos[1];
            b = startPos[0];
            ret = 0;
            for (int j = i; j < s.size(); ++j) {
                if (executeOne(n-1, &a, &b, s[j])) {
                    ++ret;
                } else {
                    break;
                }
            }
            outs.emplace_back(ret);
        }
        return outs;
    }
private:
    bool executeOne(int max_index, int* posi, int* posj, char move) {
        if (move == 'L') {
            if (*posi > 0) {
                --(*posi);
                return true;
            }
            return false;
        } else if (move == 'R') {
            if (*posi < max_index) {
                ++(*posi);
                return true;
            }
            return false;
        } else if (move == 'U') {
            if (*posj > 0) {
                --(*posj);
                return true;
            }
            return false;
        } else {
            if (*posj < max_index) {
                ++(*posj);
                return true;
            }
            return false;
        }
    }
};
