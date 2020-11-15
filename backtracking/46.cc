class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        std::unordered_map<int, int> map_;
        for (const auto& num : nums) {
            const auto& iter = map_.find(num);
            if (iter != map_.cend()) {
                ++(iter->second);
            } else {
                map_.emplace(num, 1);
            }
        }
        std::vector<std::vector<int>> ret;
        std::vector<int> cur;
        size_t length = nums.size();
        recur(ret, cur, length, map_);
        return ret;
    }
private:
    void recur(std::vector<std::vector<int>>& ret, std::vector<int>& cur, size_t& length, std::unordered_map<int, int>& map_) {
        if (cur.size() == length) {
            ret.emplace_back(cur);
            return;
        }
        for (auto iter = map_.begin(); iter != map_.end(); ++iter) {
            if (iter->second == 0)
                continue;
            cur.emplace_back(iter->first);
            --(iter->second);
            recur(ret, cur, length, map_);
            cur.pop_back();
            ++(iter->second);
        }
    }
};
