class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int n: nums) {
            freq[n]++;
        }
        // Creating indexed buckets according to the frequencies
        vector<vector<int>> bucket(nums.size()+1);
        // Place each number into it's freq bucket
        for (auto&p: freq) {
            bucket[p.second].push_back(p.first);
        }
        vector<int> ans;
        for(int i=bucket.size()-1;i>0;i--) {
            for(int n: bucket[i]) {
                ans.push_back(n);
                if (ans.size() >= k) {
                    return ans;
                }
            }
        }
        return ans;

    }
};
