class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int m = nums1.size();
        int n = nums2.size();
        int low = 0, high = m;
        int half = (m + n + 1) / 2;
        while (low <= high) {
            int mid1 = low + (high - low) / 2;
            int mid2 = half - mid1;
            int left1 = (mid1 > 0) ? nums1[mid1 - 1] : INT_MIN;
            int right1 = (mid1 < m) ? nums1[mid1] : INT_MAX;
            int left2 = (mid2 > 0) ? nums2[mid2 - 1] : INT_MIN;
            int right2 = (mid2 < n) ? nums2[mid2] : INT_MAX;
            if (left1 <= right2 && left2 <= right1) {
                if ((m + n) % 2 == 1) {
                    return max(left1, left2);
                } else {
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                }
            } else if (left1 > right2) {
                high = mid1 - 1;
            } else {
                low = mid1 + 1;
            }
        }
        return 0.0;
    }
};
