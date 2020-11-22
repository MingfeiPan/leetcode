class Solution {
public:
    string getSmallestString(int n, int k) {
        // give each number a zero
        std::vector<char> v_(n, 'a');
        k -= n;
        while (k > 25) {
            v_[n-1] += 25;
            k -= 25;
            --n;
        }
        v_[n-1] += k;
        std::string ret = "";
        for (const char& c : v_) {
            ret += c;
        }
        return ret;
    }
};
