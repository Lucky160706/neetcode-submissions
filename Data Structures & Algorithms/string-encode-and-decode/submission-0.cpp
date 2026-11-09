class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_str = "";
        for (int i = 0; i < strs.size(); i++) {
            for (int j = 0; j < strs[i].size(); j++) {
                encoded_str += strs[i][j] + 1;
            }
            encoded_str += " ";
        }
        return encoded_str;
    }

    vector<string> decode(string s) {
        string res = "";
        vector<string> decoded_strs;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                decoded_strs.push_back(res);
                res = "";
            } else {
                res += s[i] - 1;
            }
        }
        return decoded_strs;
    }
};
