class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        return nums[0];
    }
};
