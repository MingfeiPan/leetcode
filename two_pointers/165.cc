class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i1 = 0, i2 = 0, v1 = 0, v2 = 0;
        while (i1 < version1.size() && i2 < version2.size()) {
            v1 = trans(i1, version1);
            v2 = trans(i2, version2);
            if (v1 < v2) return -1;
            if (v2 < v1) return 1;
        }
        while (i1 < version1.size()) {
            v1 = trans(i1, version1);
            if (v1 != 0) return 1;
        }
        while (i2 < version2.size()) {
            v2 = trans(i2, version2);
            if (v2 != 0) return -1;
        }
        return 0;
    }
private:
    int trans(int& index, std::string s) {
        std::string temp = "";
        while (index < s.size()) {
            if (s[index] == '.') {
                ++index;
                break;
            }
            temp += s[index];
            ++index;
        }
        if (temp == "") return 0;
        int ret = 0;
        for (const auto& c : temp) {
            ret = ret * 10 + c-'0';
        }
        return ret;
    }
};
