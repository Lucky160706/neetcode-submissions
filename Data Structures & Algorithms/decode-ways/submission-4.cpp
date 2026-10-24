class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();

        int prev1 = 1;
        int prev2 = 0;

        for (int i = n - 1; i >= 0; i--) {
            int curr = 0;
            if (s[i] != '0') {
                curr = prev1;

                if (i + 1 < n) {
                    int num = (s[i] - '0') * 10 + (s[i + 1] - '0');

                    if (num >= 10 && num <= 26) {
                        curr += prev2;
                    }
                }
            }
        

            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }
};
