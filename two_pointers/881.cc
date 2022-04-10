class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        std::sort(people.begin(), people.end());
        int i = 0, ret = 0, j = people.size() - 1;
        while (i <= j) {
            ++ret;
            if ((people[i]+people[j]) <= limit) ++i;
            --j;
        }
        return ret;
    }
};
