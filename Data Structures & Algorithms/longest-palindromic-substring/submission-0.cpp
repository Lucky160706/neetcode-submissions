class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int left, right;
        string ans = "";
        for (int i = 0; i < s.size(); ++i) {
            // Odd-length palindrome
            int left = i;
            int right = i;

            while (left >= 0 && right < n &&
                   s[left] == s[right]) {
                left--;
                right++;
            }

            int length = right - left - 1;

            if (length > ans.size()) {
                ans = s.substr(left + 1, length);
            }

            // Even-length palindrome
            left = i;
            right = i + 1;

            while (left >= 0 && right < n &&
                   s[left] == s[right]) {
                left--;
                right++;
            }

            length = right - left - 1;

            if (length > ans.size()) {
                ans = s.substr(left + 1, length);
            }
        }
        return ans;
    }
};
