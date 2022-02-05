class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        std::unordered_map<char, int> m;
        int counter = 0;
        for (const auto& c : p) {
            auto iter = m.find(c);
            if (iter == m.end()) {
                ++counter;
                m[c] = 1;
            } else {
                ++m[c];
            }
        }
        int begin = 0, end = 0;
        std::vector<int> ret;
        while (end < s.size()) {
            auto iter_end = m.find(s[end]);
            if (iter_end != m.end()) {
                --m[s[end]];
                if (0 == m[s[end]]) --counter;
            }
            ++end;
            while (0 == counter) {
                auto iter_begin = m.find(s[begin]);
                if (iter_begin != m.end()) {
                    ++m[s[begin]];
                    if (m[s[begin]] > 0) ++counter;
                }
                if ((end - begin) == p.size()) 
                    ret.emplace_back(begin);
                ++begin;
            }
        }
        return  ret;
    }
};
