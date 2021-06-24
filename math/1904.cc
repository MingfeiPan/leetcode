class Solution {
public:
    int numberOfRounds(string startTime, string finishTime) {
        int start = stoi(startTime.substr(0,2)) * 60 + stoi(startTime.substr(3,2));
        int fin = stoi(finishTime.substr(0,2)) * 60 + stoi(finishTime.substr(3,2));
                                                              
        if (start > fin) {
            fin += 24 * 60;
        }
        return std::max(0, fin / 15 - (start + 14) / 15);
                                                              
    }
};
