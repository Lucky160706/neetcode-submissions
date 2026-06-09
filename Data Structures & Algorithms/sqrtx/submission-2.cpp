class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        long mid = 0;
        int ans = 0;
        while (l <= r) {
            mid = (long) (l + r) / 2;
            if (mid * mid > x) {
                r = mid - 1;
                ans = r;
            } else if (mid * mid < x) {
                l = mid + 1;
            } else {
                return mid;
            }
        }
        return ans;
    }
};