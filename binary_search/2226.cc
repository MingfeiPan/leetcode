class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int left = 1, right = *max_element(begin(candies), end(candies));
        auto check = [&](int64_t num) {
            int64_t count = 0;
            for (const auto& i : candies) {
                count += i / num;
                if (count >= k) return true;
            }
            return false;
        };
        while (left <= right) {
            int mid = (left + right) / 2;
            if (check(mid)) left = mid+1;
            else right = mid-1;
        }
        return right;
    }
};
