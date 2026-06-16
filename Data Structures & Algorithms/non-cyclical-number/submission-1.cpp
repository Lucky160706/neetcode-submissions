class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> sett;
        int temp = n;
        int res = 0;
        while (n != 1 && sett.find(n) == sett.end()) {
            sett.insert(n);

            int res = 0;
            while (n > 0) {
                res += (n % 10) * (n % 10);
                n /= 10;
            }

            n = res;
        }
        return n == 1;
    }
};
