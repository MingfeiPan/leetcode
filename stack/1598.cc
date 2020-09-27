class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ret = 0;
        for (auto log : logs) {
            if (log.compare("../") == 0) {
                if (ret > 0)
                    ret--;
            } else if (log.compare("./") == 0) {
                continue;
            } else {
                ret++;
            }
        }
        return ret;
    }
};
