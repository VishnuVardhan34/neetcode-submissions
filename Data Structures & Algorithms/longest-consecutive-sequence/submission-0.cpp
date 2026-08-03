class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mp(nums.begin(), nums.end());
        int longest =0;
        for (int n: nums) {
            // Check for the start of the sequence
            if (mp.count(n-1)) continue;
            int curr = n;
            int length =1;
            while(mp.count(curr+1)) {
                curr++;
                length++;
            }
            longest = max(longest, length);
        }
        return longest;
    }
};
