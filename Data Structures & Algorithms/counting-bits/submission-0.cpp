class Solution {
public:
    int Bit1(int res) {
        int cnt = 0;
        while (res) {
            cnt += res & 1;
            res >>= 1;
        }
        return cnt;
    }
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        for (int i = 0; i <= n; i++) {
            ans[i] = Bit1(i);
        }
        return ans;
    }
};
