class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>counts;
        for(int num : nums){
            counts[num]++;
        }
        vector<vector<int>> buckets(nums.size() + 1);
        for(auto& b : counts){
            int element = b.first;
            int frequency = b.second;
            buckets[frequency].push_back(element);
        }
        vector<int>result;
        for(int i = buckets.size()-1; i >= 0; i--){
            for(int num : buckets[i]){
                result.push_back(num);
                if(result.size() == k){
                    return result;
                }
            }
        }
        return result;
    }
};
