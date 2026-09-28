class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if (n <= 1) return n;
        vector<pair<int, int>> cars(n);
        for (int i = 0; i < n; i++) {
            cars[i] = {position[i], speed[i]};
        }
        sort(cars.rbegin(), cars.rend());
        int fleets = 0;
        double maxTime = 0.0;
        for(int i = 0; i < n; i++){
            double time = static_cast<double>(target - cars[i].first)/cars[i].second;
            if(time>maxTime){
                maxTime = time;
                fleets++;
            }
        }
        return fleets;
    }
};
