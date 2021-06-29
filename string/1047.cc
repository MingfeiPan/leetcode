class Solution {
public:
    string removeDuplicates(string s) {
        int index = 0;
        
        while (!s.empty() && index < (s.size()-1)) {
            if (s[index] == s[index+1]) {
                if ((index+2) < s.size()) {
                    s = s.substr(0, index) + s.substr(index+2);        
                } else {
                    s = s.substr(0, index);
                }
                if (index > 0)
                    --index;
            } else {
                ++index;
            }
        }
        return s;
    }
};
