class Solution {
public:
    bool checkString(string s) {
        bool b_found = false;
        for (const auto& c : s) {
            if (c == 'a' && b_found)
                return false;
            if (c == 'b')
                b_found = true;
        }
        return true;
    }
};
