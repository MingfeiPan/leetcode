class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        std::vector<int> s_;
        int i = 0;
        while (i < asteroids.size()) {
            if (asteroids[i] > 0) {
                s_.emplace_back(asteroids[i]);
                i++;
            } else {
                if (s_.empty() || s_[s_.size()-1] < 0) {
                    s_.emplace_back(asteroids[i]);
                    i++;
                    continue;    
                }
                if ((s_[s_.size()-1] + asteroids[i]) == 0) {
                    s_.pop_back();
                    i++;
                } else if ((s_[s_.size()-1] + asteroids[i]) > 0) {
                    i++;
                } else {
                    s_.pop_back();
                }
            }
        }
        return s_;
        
    }
};
