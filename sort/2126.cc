class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int64_t temp = mass;
        std::sort(asteroids.begin(), asteroids.end());
        for (const auto& i : asteroids) {
            if (temp < i)
                return false;
            temp +=i;
        }
        return true;
    }
};
