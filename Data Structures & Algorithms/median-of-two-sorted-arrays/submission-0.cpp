class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        // Always binary search on the smaller array
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size();
        int n = nums2.size();

        int low = 0;
        int high = m;

        while (low <= high) {

            int partitionA = (low + high) / 2;
            int partitionB = (m + n + 1) / 2 - partitionA;

            int aLeft  = (partitionA == 0) ? INT_MIN : nums1[partitionA - 1];
            int aRight = (partitionA == m) ? INT_MAX : nums1[partitionA];

            int bLeft  = (partitionB == 0) ? INT_MIN : nums2[partitionB - 1];
            int bRight = (partitionB == n) ? INT_MAX : nums2[partitionB];

            if (aLeft <= bRight && bLeft <= aRight) {

                if ((m + n) % 2 == 0) {
                    return (max(aLeft, bLeft) + min(aRight, bRight)) / 2.0;
                }

                return max(aLeft, bLeft);
            }

            else if (aLeft > bRight) {
                high = partitionA - 1;
            }

            else {
                low = partitionA + 1;
            }
        }

        return 0.0;
    }
};