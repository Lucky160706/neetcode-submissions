class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            long long var = mid * mid;
            if (var > x) {
                r = mid - 1;
            } else if (var < x) {
                l = mid + 1;
            } else {
                return mid;
            }
        }
        return r;
    }
};