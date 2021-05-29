class Solution {
public:
    int characterReplacement(string s, int k) {
        int ret = 0, i = 0, max = 0;
        std::vector<int> v(26, 0);
        for (int j = 0; j < s.size(); ++j) {
            ++v[s[j]-'A'];
            max = std::max(max, v[s[j]-'A']);
            while ((j-i+1) > (max + k)) {
                --v[s[i]-'A'];
                ++i;
            }    
            ret = std::max(ret, j-i+1);
        }
        return ret;
    }
};
