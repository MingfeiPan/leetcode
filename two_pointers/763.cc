class Solution {
public:
    vector<int> partitionLabels(string s) {
        std::vector<int> last(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            last[s[i] - 'a'] = i;
        }
        int start = 0, end = 0;
        std::vector<int> ret;
        for (int i = 0; i < s.size(); ++i) {
            end = std::max(end, last[s[i] - 'a']);
            if (i == end) {
                ret.emplace_back(end - start + 1);
                start = i + 1;
            }
        }
        return ret;
    }
};
