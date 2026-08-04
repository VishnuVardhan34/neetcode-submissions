class Solution {
public:
    int trap(vector<int>& heights) {
        if (heights.empty()) return 0;
        int l=0,r=heights.size()-1;
        int lMax = heights[l], rMax = heights[r], ans=0;
        while(l<r) {
            if (lMax < rMax) {
                l++;
                lMax = max(lMax, heights[l]);
                ans += lMax  - heights[l];
            } else {
                r--;
                rMax = max(rMax, heights[r]);
                ans += rMax - heights[r];
            }
        }
        return ans;
    }
};
