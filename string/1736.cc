class Solution {
public:
    string maximumTime(string time) {
        std::string ret = "";
        if (time[0] == '?' && time[1] == '?') {
            ret += "23";
        } else if (time[0] == '?') {
            if (time[1] < '4') {
                ret += "2";
            } else {
                ret += "1";
            }
            ret += time[1];
        } else if (time[1] == '?') {
            if (time[0] == '2') {
                ret += "23";
            } else {
                ret += string(1, time[0]) + "9";
            }
        } else {
            ret += time.substr(0,2);
        }
        ret += ":";
        if (time[3] == '?' && time[4] == '?') {
            ret += "59";
        } else if (time[3] == '?') {
            ret += "5" + string(1, time[4]);
        } else if (time[4] == '?') {
            ret += string(1, time[3]) + "9";
        } else {
            ret += time.substr(3,2);
        }
        return ret;
    }
};
