class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) {
            return "";
        }

        vector<int> arr1(256, 0);
        vector<int> arr2(256, 0);

        for (char c : t) {
            arr1[c]++;
        }

        int required = 0;

        // The number of required distinct character in the substr
        for (int count : arr1) {
            if (count > 0) required++;
        }

        int size_substr = INT_MAX;
        int start = 0;
        int formed = 0;
        int bestStart = 0;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            arr2[c]++;

            // Check if the letter in substr also in t
            // and the number of that character is the same in
            // that substr and t.
            if (arr1[c] > 0 && arr2[c] == arr1[c]) {
                formed++;
            }

            while (formed == required) {
                int sizeWindow = i - start + 1;

                if (sizeWindow < size_substr) {
                    size_substr = sizeWindow;
                    bestStart = start;
                }

                char left = s[start];
                arr2[left]--;

                if (arr1[left] > 0 && arr2[left] < arr1[left]) {
                    formed--;
                }

                start++;
            }
        }

        if (size_substr == INT_MAX) return "";

        return s.substr(bestStart, size_substr);
    }
};
