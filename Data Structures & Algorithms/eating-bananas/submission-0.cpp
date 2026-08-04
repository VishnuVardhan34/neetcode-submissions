class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while (left < right) {
            int mid = left + (right - left) / 2;

            long long hours = 0;

            for (int pile : piles) {
                // Ceiling division
                hours += (pile + mid - 1) / mid;
            }

            if (hours <= h) {
                // This speed works.
                // Try to find a smaller valid speed.
                right = mid;
            } else {
                // Too slow.
                left = mid + 1;
            }
        }

        return left;
    }
};