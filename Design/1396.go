import java.util.*;
class UndergroundSystem {

    private Map<Integer, PersonInfo> personMap;
    private Map<String, List<Integer>> stationMap;
    
    public UndergroundSystem() {
        this.personMap = new HashMap<>();
        this.stationMap = new HashMap<>();
    }
    
    public void checkIn(int id, String stationName, int t) {
        PersonInfo info = new PersonInfo();
        info.station = stationName;
        info.time = t;
        this.personMap.put(id, info);
    }
    
    public void checkOut(int id, String stationName, int t) {
        PersonInfo info = this.personMap.get(id);
        String stations = info.station+stationName;
        if (this.stationMap.get(stations) == null) {
            List<Integer> newList = new ArrayList<>();
            newList.add(t - info.time);
            this.stationMap.put(stations, newList);
        } else {
            List<Integer> list = this.stationMap.get(stations);
            list.add(t - info.time);
            this.stationMap.put(stations, list);
        }
            
    }
    
    public double getAverageTime(String startStation, String endStation) {
        String stations = startStation + endStation;
        List<Integer> list = this.stationMap.get(stations);
        double ret = 0.0;
        for (int i = 0; i < list.size(); i++) {
            ret += list.get(i);
        }
        return ret / list.size();
    }
    public class PersonInfo {
        public String station;
        public Integer time;
    }
}

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem obj = new UndergroundSystem();
 * obj.checkIn(id,stationName,t);
 * obj.checkOut(id,stationName,t);
 * double param_3 = obj.getAverageTime(startStation,endStation);
 */
