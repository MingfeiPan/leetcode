class Solution {
public:
    string addStrings(string num1, string num2) {
        std::string ret = "";
        if (num1.empty() && num2.empty())
            return ret;
        int i1 = num1.size()-1, i2 = num2.size()-1, temp = 0;
        bool flag = false;
        while (i1 >= 0 && i2 >= 0) {
            int first = num1[i1] - '0';
            int second = num2[i2] - '0';
            temp = first + second;
            if (flag) {
                ++temp;
                flag = false;
            }
            if (temp > 9) {
                temp -= 10;
                flag = true;
            }
            ret = std::to_string(temp) + ret;
            --i1;
            --i2;
        }
        while (i1 >= 0) {
            int first = num1[i1] - '0';
            temp = first;
            if (flag) {
                ++temp;
                flag = false;
            }
            if (temp > 9) {
                temp -= 10;
                flag = true;
            }
            ret = std::to_string(temp) + ret;
            --i1;           
        }
        while (i2 >= 0) {
            int first = num2[i2] - '0';
            temp = first;
            if (flag) {
                ++temp;
                flag = false;
            }
            if (temp > 9) {
                temp -= 10;
                flag = true;
            }
            ret = std::to_string(temp) + ret;
            --i2;           
        }
        if (flag)
            ret = "1" + ret;
        return ret;
    }
};
