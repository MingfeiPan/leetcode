class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int counter_one = 0, counter_flip = 0;
        for (const auto& c : s) {
            if (c == '1') {
                ++counter_one;    
            } else {
                counter_flip = std::min(counter_one, counter_flip+1);
            }
        }
        return counter_flip;
    }
};
