class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ret = 0;
        for (const auto& word : words) {
            if (word.size() < pref.size()) continue;
            if (word.substr(0, pref.size()) == pref) ++ret;
        }
        return ret;
    }
};
