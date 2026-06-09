class Solution {
public:
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
    void sortColors(vector<int>& nums) {
        int l, m, r;
        l = m = 0;
        r = nums.size() - 1;
        int i = 0;
        while (m <= r) {
            cout << "Iteration: " << i + 1 << endl;
            cout << "l: " << l << ", m: " << m << ", r: " << r << endl;
            if (nums[m] == 0) {
                swap(nums[m], nums[l]);
                l++;
                m++;
            } else if (nums[m] == 2) {
                if (nums[r] != 2) {
                    swap(nums[m], nums[r]);
                }
                r--;
            } else if (nums[m] == 1) {
                m++;
            }
            i += 1;
        }
    }
};