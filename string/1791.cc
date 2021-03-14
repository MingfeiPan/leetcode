class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        size_t index = 0, count = 0;
        std::vector<size_t> arr;
        while (index < s1.size()) {
            if (s1[index] != s2[index]) {
                ++count;
                if (count > 2)
                    return false;
                arr.emplace_back(index);
            }
            ++index;
        }
        if (count == 0)
            return true;
        if (count == 1)
            return false;
        if (s1[arr[0]] == s2[arr[1]] && s1[arr[1]] == s2[arr[0]])
            return true;
        return false;
    }
};
