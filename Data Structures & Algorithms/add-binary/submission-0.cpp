class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";

        int res = 0;
        int keep = 0;

        int i = a.size() - 1;
        int j = b.size() - 1;

        while (i >= 0 || j >= 0 || keep > 0) {
            int first = 0;
            int second = 0;

            if (i >= 0) {
                first = a[i] - '0';
                i--;
            }

            if (j >= 0) {
                second = b[j] - '0';
                j--;
            }

            int sum = first + second + keep;

            int res = sum % 2;
            keep = sum / 2;

            ans += (res + '0');
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};