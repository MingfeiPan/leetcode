class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        std::vector<int> counter(26, 0);
        for (const auto& c : s) {
            ++counter[c-'a'];
        }
        std::string ret = "";
        int count = 0, last = -1;
        bool found = true;
        while (found) {
            found = false;
            for (int i = 25; i >= 0 && !found; --i) {
                if (counter[i] > 0 && (count < repeatLimit || last != i)) {
                    ret += i + 'a';
                    --counter[i];
                    ++count;
                    if (last != i) count = 1;
                    last = i;
                    found = true;
                }
            }
        }
        return ret;
    }
};
