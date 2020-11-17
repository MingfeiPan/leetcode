class Solution {
public:
    bool closeStrings(string word1, string word2) {
        std::vector<int> v1(26, 0), v2(26, 0);
        std::unordered_set<char> s1, s2;
        for (const auto& c: word1) {
            v1[c-'a']++;
            s1.emplace(c);
        }
        for (const auto& c: word2) {
            v2[c-'a']++;
            s2.emplace(c);
        }
        std::sort(v1.begin(), v1.end());
        std::sort(v2.begin(), v2.end());
        return s1 == s2 && v1 == v2;
    }
};
