class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> idht;
    map<pair<string, string>, int> m1;
    map<pair<string, string>, int> m2;
    
    UndergroundSystem() {
    }
    
    void checkIn(int id, string stationName, int t) {
        idht[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        m1[{idht[id].first, stationName}] += t - idht[id].second;
        m2[{idht[id].first, stationName}]++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        return (double)m1[{startStation, endStation}] / m2[{startStation, endStation}];
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */