class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        for (int i=0;i<position.size();i++) {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.rbegin(), cars.rend()); //decending order accoriding to posotions
        double lastFleetTime=0;
        int fleets=0;
        for(auto& car: cars) {
            double time = (double)(target - car.first) / car.second;
            if(time > lastFleetTime) {
                fleets++;
                lastFleetTime=time;
            }
        }
        return fleets;
    }
};
