class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int n: nums) count[n]++;
        vector<vector<int>> freq(nums.size()+1);
        for (auto& [k, v]: count) {
            freq[v].push_back(k);
        }
        vector<int> ans;
        for(int i=freq.size()-1;i>0;i--) {
            for(int j: freq[i]) {
                ans.push_back(j);
                if(ans.size() >= k) return ans;
            }
        }
        return ans;
    }
};
