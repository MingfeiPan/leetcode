class Solution {
public:
    bool isValidSerialization(string preorder) {
        int diff = 1;
        std::string temp = "";
        for (const auto &c : preorder) {
            if (c == ',') {
                --diff;
                if (diff < 0)
                    return false;
                if (temp != "#")
                    diff += 2;
                temp = "";
            } else {
                temp += c;
            }
        }
        --diff;
        if (diff < 0)
            return false;
        if (temp != "#")
            diff += 2;        
        return diff == 0;
    }
};
