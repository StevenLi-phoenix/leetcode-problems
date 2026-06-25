// @leetcode id=1396 questionId=1512 slug=design-underground-system lang=cpp site=leetcode.com title="Design Underground System"
class UndergroundSystem {
private:
    // Map to store check-in info: id -> {station, time}
    unordered_map<int, pair<string, int>> checkInMap;
    
    // Map to store average time: "start-end" -> {total_time, count}
    unordered_map<string, pair<long long, int>> routeStats;
    
public:
    UndergroundSystem() {
    }
    
    void checkIn(int id, string stationName, int t) {
        checkInMap[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto [startStation, startTime] = checkInMap[id];
        string route = startStation + "-" + stationName;
        int travelTime = t - startTime;
        
        routeStats[route].first += travelTime;
        routeStats[route].second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route = startStation + "-" + endStation;
        auto [totalTime, count] = routeStats[route];
        return (double)totalTime / count;
    }
};
