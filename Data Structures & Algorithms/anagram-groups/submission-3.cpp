class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashmap;
        for (string &str : strs) {
            string sorted_str = str;
            sort(sorted_str.begin(), sorted_str.end());
            hashmap[sorted_str].push_back(move(str));
        }
        vector<vector<string>> ans;
        ans.reserve(hashmap.size());
        for (auto &temp : hashmap) {
            ans.push_back(move(temp.second));
        }
        return ans;
    }
};
