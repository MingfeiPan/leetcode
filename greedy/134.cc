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
