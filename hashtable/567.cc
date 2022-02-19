class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        std::vector<int> m1(26, 0), m2(26, 0);
        for (int i = 0; i < s1.size(); ++i) {
            ++m1[s1[i]-'a'];
            ++m2[s2[i]-'a'];
        }
        if (match(m1, m2)) return true;
        for (int i = 0; i < (s2.size()-s1.size()); ++i) {
            --m2[s2[i]-'a'];
            ++m2[s2[i+s1.size()]-'a'];
            if (match(m1, m2)) return true;
        }        
        return false;
    }
private:
    bool match(std::vector<int>& v1, std::vector<int>& v2) {
        for (int i = 0; i < v1.size(); ++i) {
            if (v1[i] != v2[i]) return false;
        }
        return true;
    }
};
