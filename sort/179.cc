class Solution {
public:
    string largestNumber(vector<int>& nums) {
        std::vector<std::string> strs;
        for (auto num: nums) {
            strs.emplace_back(std::to_string(num));
        }
        std::sort(strs.begin(), strs.end(), [](std::string a, std::string b){
            return (a+b) > (b+a);
        });
        std::string ret = "";
        if (strs.size() > 0 && strs[0] == "0") {
            return "0";
        }
        for (auto s : strs) {
            ret += s;
        }
        return ret;
    }
};
