class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if (x < arr[0]) {
            arr.resize(k);
            return arr;
        } else if (x > arr[arr.size()-1]) {
            std::vector<int> ret(arr.begin() + int(arr.size()) - k, arr.end());
            return ret;
        } else {
            int index = binary_search(arr, x);
            std::vector<int> ret;
            int left = index-1;
            int right = index;
            while (k > 0 && left >= 0 && right < arr.size()) {
                int abs_left = std::abs(arr[left] - x);
                int abs_right = std::abs(arr[right] - x);
                if (abs_left <= abs_right) {
                    auto iter = ret.begin();
                    ret.insert(iter, arr[left]);
                    --left;
                } else {
                    ret.emplace_back(arr[right]);
                    ++right;
                }
                --k;
            }
            while (k > 0) {
                if (left >= 0) {
                    auto iter = ret.begin();
                    ret.insert(iter, arr[left]);
                    --left;                        
                } else {
                    ret.emplace_back(arr[right]);
                    ++right;                    
                }
                --k;
            }       
            return ret;
        }
        return arr;
    }
private:
    int binary_search(std::vector<int>& nums, int target) {
        int begin = 0, end = nums.size() - 1, mid = 0;
        while (begin < end) {
            mid = (end + begin) / 2;
            if (nums[mid] >= target) {
                end = mid;
            } else {
                begin = mid + 1;
            }
        }
        return begin;
    }
};
