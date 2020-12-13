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
