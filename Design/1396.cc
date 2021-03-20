class UndergroundSystem {
    
struct CheckItem {
    std::string stationName;
    int timestamp;
};

struct CountItem {
    int total;
    int count;
};
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkMap_.emplace(id, CheckItem{stationName, t});
    }
    
    void checkOut(int id, string stationName, int t) {
        CheckItem item = checkMap_[id];
        auto iter = itemMap_.find(item.stationName+sep_+stationName);
        if (iter == itemMap_.end()) {
            itemMap_.emplace(item.stationName+sep_+stationName, CountItem{t-item.timestamp, 1});
        } else {
            iter->second.count++;
            iter->second.total += t-item.timestamp;
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto iter = itemMap_.find(startStation+sep_+endStation);
        return (double) iter->second.total / iter->second.count;
    }
private:
    std::unordered_map<int, CheckItem> checkMap_;
    std::unordered_map<std::string, CountItem> itemMap_;
    std::string sep_ = "_";
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
