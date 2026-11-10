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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right || head->next == nullptr) return head;

        ListNode dummy(0);
        dummy.next = head;

        // Find node before left
        ListNode* beforeLeft = &dummy;

        for (int i = 1; i < left; i++) {
            beforeLeft = beforeLeft->next;
        }

        ListNode* afterRight = &dummy;

        // Reverse nodes from left to right
        ListNode* leftNode = beforeLeft->next;
        ListNode* curr = leftNode;
        ListNode* prev = nullptr;

        for (int i = left; i <= right; i++) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Reconnect the reversed section
        beforeLeft->next = prev;
        leftNode->next = curr;

        return dummy.next;
    }
};