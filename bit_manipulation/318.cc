class Solution {
public:
    int maxProduct(vector<string>& words) {
        std::unordered_map<int, std::bitset<26> > m;
        for (int i = 0; i < words.size(); ++i) {
            for (const auto &c : words[i]) {
                m[i][c - 'a'] = 1;
            }
        }
        int ret = 0;
        bool flag = false;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = i+1; j < words.size(); ++j) {
                flag = true;
                for (int k = 0; k < 26; ++k) {
                    if (m[i][k] & m[j][k]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    int cur = words[i].size() * words[j].size();
                    ret = std::max(ret, cur);
                }
            }
        }
        return ret;
    }
};
