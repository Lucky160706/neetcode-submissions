/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* p = dummy;
        int temp = 0, total = 0;
        while (l1 || l2) {
            if (l2) {
                total += l2 -> val;
                l2 = l2 -> next;
            } 
            if (l1) {
                total += l1 -> val;
                l1 = l1 -> next;
            }
            total += temp;
            cout << total << " " << total % 10 << endl;
            p -> next = new ListNode(total % 10);
            cout << p -> val << endl;
            temp = total / 10;
            p = p -> next;
            cout << p -> val << endl;
            total = 0;
        }
        if (temp) {
            p -> next = new ListNode(1);
        }
        return dummy -> next;
    }
};
