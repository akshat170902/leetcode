class UndergroundSystem {
    unordered_map<string,unordered_map<string,vector<int>>>time;
    unordered_map<int,pair<string,int>>counter;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        counter[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        time[counter[id].first][stationName].push_back(t-counter[id].second);
    }
    
    double getAverageTime(string startStation, string endStation) {
        int n=time[startStation][endStation].size();
        int val=0;
        for(int value:time[startStation][endStation]){
            val+=value;
        }
        return (double)val/(double)n;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */