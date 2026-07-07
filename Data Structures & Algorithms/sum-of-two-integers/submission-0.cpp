class Solution {
public:
    int getSum(int a, int b) {
        int total, carry;
        while (b) {
            total = a ^ b;
            carry = (a & b) << 1;
            a = total;
            b = carry;
        }
        return total;
    }
};
