class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int duration = releaseTimes[0];
        char ret = keysPressed[0];
        for (int i = 1; i < keysPressed.size(); i++) {
            if ((releaseTimes[i] - releaseTimes[i-1]) > duration) {
                duration = releaseTimes[i] - releaseTimes[i-1];
                ret = keysPressed[i];
            } else if ((releaseTimes[i] - releaseTimes[i-1]) == duration) {
                if (ret < keysPressed[i]) {
                    ret = keysPressed[i];
                }
            }
        }
        return ret;
    }
};
