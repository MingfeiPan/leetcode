class OrderedStream {
public:
    OrderedStream(int n) {
        return;
    }
    
    vector<string> insert(int id, string value) {
        std::vector<std::string> ret;
        if (id != ptr) {
            map_.emplace(id, value);
            return ret;
        }
        ret.emplace_back(value);
        ++id;
        while (true) {
            const auto& iter = map_.find(id);
            if (iter != map_.cend()) {
                ret.emplace_back(iter->second);
                map_.erase(id);
                ++id;
            } else {
                break;
            }
        }
        ptr = id;
        return ret;
    }
private:
    int ptr = 1;
    std::unordered_map<int, std::string> map_;
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */
