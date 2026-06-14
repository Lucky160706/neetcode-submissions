class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        const int n = arr.size();
        if (k == n) return arr;
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(arr[i]);
        }    
        // for (int num : ans) {
        //         cout << num << ", ";
        //     }
        //     cout << endl;
        for (int i = k; i < n; i++) {
            if ( 
            (abs(ans[0] - x) > abs(arr[i] - x)) 
            || (abs(ans[0] - x) == abs(arr[i] - x) 
            && ans[0] > arr[i])
            ) {
                ans.erase(ans.begin());
                // j++;
                ans.push_back(arr[i]);
            }
            // for (int num : ans) {
            //     cout << num << ", ";
            // }
            // cout << endl;
        }
        return ans;
    }
};