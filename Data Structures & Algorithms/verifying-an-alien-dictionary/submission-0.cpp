class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int rank[26];

        for (int i = 0; i < order.size(); i++) {
            rank[order[i] - 'a'] = i;
        }

        for (int i = 0; i < words.size() - 1; i++) {
            string& first = words[i];
            string& second = words[i + 1];

            int j = 0;

            while (j < first.size() && j < second.size()) {
                if (rank[first[j] - 'a'] > rank[second[j] - 'a']) {
                    return false;
                } else if (rank[first[j] - 'a'] == rank[second[j] - 'a']) {
                    j++;
                } else {
                    break;
                }
            }

            if (j < first.size() && j == second.size()) {
                return false;
            }
        }
        return true;
    }
};