class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (gas.empty()) {
            return -1;
        }
        int start_index = 0;
        int total = 0;
        int charge = 0;
        for(size_t i = 0; i < gas.size(); i++) {
            charge += gas[i] - cost[i];
            if (charge < 0) {
                total += charge;
                charge = 0;
                start_index = i+1;
            }
        }
        total += charge;
        if (total < 0) {
            return -1;
        }
        return start_index;
    }
};

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int cur = 0, index = 0, total = 0;
        for (int i = 0; i < gas.size(); ++i) {
            int left = gas[i] - cost[i];
            cur += left;
            total += left;
            if (cur < 0) {
                index = i+1;
                cur = 0;
            }
        }
        if (total < 0)
            return -1;
        return index;
    }
};


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int index = 0, max = INT_MAX, total = 0;
        for (int i = 0; i < gas.size(); ++i) {
            total += gas[i] - cost[i];
            if (total < max) {
                index = i+1;
                max = total;
            }
        }
        if (total < 0)
            return -1;
        return index % gas.size();
    }
};
