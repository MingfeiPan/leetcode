class Solution {
public:
    int minPartitions(string n) {
        char cur = '0';
        for (auto& c : n) {
            if (c > cur) {
                cur = c;
            }
            if (cur == '9')
                break;
        }
        return int(cur-'0');
    }
};

class Solution {
public:
    int minPartitions(string n) {
        int ret = 0;
        for (const auto &c : n) {
            ret = std::max(ret, c-'0');
            if (ret == 9)
                return ret;
        }
        return ret;
    }
};
