class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> t(rowIndex + 1);
        for (int i = 0; i <= rowIndex; i++) {
            t[i].resize(i + 1);

            t[i][0] = 1;
            t[i][i] = 1;

            for (int j = 1; j < i; j++) {
                t[i][j] = t[i - 1][j - 1] + t[i - 1][j];
            }
        }
        return t[rowIndex];
    }
};