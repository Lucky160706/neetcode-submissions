class Solution {
public:
    int countSubstrings(string s) {
        // Declare variable
        int left, right;
        int length;

        // Initialize 
        int n = s.size();
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            left = i;
            right = i;

            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
                cnt++;
            }

            left = i;
            right = i + 1;

            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
                cnt++;
            }
        }

        return cnt;
    }
};
