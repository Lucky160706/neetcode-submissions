class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int n = nums1.size();
        int m = nums2.size();
        int maxLeft1, maxLeft2, minRight1, minRight2;
        int i, j;
        int l = 0, r = min(n, m);
        while (l <= r) {
            i = (l + r) / 2;
            j = (n + m + 1) / 2 - i;
            int maxLeft1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int minRight1 = (i == n) ? INT_MAX : nums1[i];
            
            int maxLeft2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int minRight2 = (j == m) ? INT_MAX : nums2[j];
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                // Nếu tổng số phần tử là lẻ
                if ((n + m) % 2 != 0) {
                    return max(maxLeft1, maxLeft2);
                }
                // Nếu tổng số phần tử là chẵn
                return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
            } 
            // Nếu vết cắt i quá lớn, dịch sang trái
            else if (maxLeft1 > minRight2) {
                r = i - 1;
            } 
            // Nếu vết cắt i quá nhỏ, dịch sang phải
            else {
                l = i + 1;
            }
        }
        return i;
    }
};