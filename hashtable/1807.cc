class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        std::unordered_map<std::string, std::string> kmap;
        for (const auto &pair : knowledge) {
            kmap[pair[0]] = pair[1];
        }
        std::string ret = "";
        std::string temp = "";
        bool flag = false;
        for (const auto &c : s) {
            if (flag) {
                if (c == ')') {
                    auto iter = kmap.find(temp);
                    if (iter == kmap.end()) {
                        ret += '?';    
                    } else {
                        ret += iter->second;    
                    }
                    flag = false;
                    temp = "";
                } else {
                    temp += c;
                }
            } else {
                if (c == '(') {
                    flag = true;
                } else {
                    ret += c;
                }
            }
        }
        return ret;
    }
};
