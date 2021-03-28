class Solution {
public:
    int numDifferentIntegers(string word) {
        std::unordered_set<char> nums = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        std::unordered_set<std::string> ret;
        bool flag = false;
        std::string temp = "";
        for (const auto &c : word) {
            auto iter = nums.find(c);
            if (flag) {
                if (iter == nums.end()) {
                    while (temp[0] == '0') {
                        temp = temp.substr(1, temp.size()-1);
                    }
                    if (temp == "") {
                        ret.emplace("0");
                    } else {
                        ret.emplace(temp);    
                    }
                    flag = false;
                    temp = "";
                } else {
                    temp += c;
                }    
            } else {
                if (iter != nums.end()) {
                    temp += c;
                    flag = true;
                }
            }
        }
        if (flag) {
            while (temp[0] == '0') {
                temp = temp.substr(1, temp.size()-1);
            }
            if (temp == "") {
                ret.emplace("0");
            } else {
                ret.emplace(temp);    
            }            
        }
        return ret.size();
    }
};
