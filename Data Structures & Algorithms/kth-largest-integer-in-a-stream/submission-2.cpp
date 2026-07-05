class KthLargest {
private: 
    priority_queue<int, vector<int>, greater<int>> res;
    int my_k;
public:
    KthLargest(int k, vector<int>& nums) {
        my_k = k;

        for (int num : nums) {
            res.push(num);
            if (res.size() > my_k) {
                res.pop();
            }
        }
    }
    
    int add(int val) {
        res.push(val);
        if (res.size() > my_k) {
            res.pop();
        }
        return res.top();
    }
};
