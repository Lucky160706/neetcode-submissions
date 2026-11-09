class Solution {
public:
    int characterReplacement(string s, int k) {
        int arr[26] = {0};
        int maxf = 0;
        int start = 0;
        int sizeWindow;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            arr[s[i] - 'A']++;

            // Count the max frequency
            maxf = max(maxf, arr[s[i] - 'A']);

            // Calculate the size of window
            sizeWindow = i - start + 1;

            if (sizeWindow - maxf <= k) {
                // The window is valid
                ans = max(ans, sizeWindow);
            } else {
                while (i - start + 1 - maxf > k) {
                    arr[s[start] - 'A']--;
                    start++;
                }
                ans = max(ans, i - start + 1);
            }
        }

        return ans;
    }
};
