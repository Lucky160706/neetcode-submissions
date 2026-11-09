/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int min_val = min(p->val, q->val);
        int max_val = max(p->val, q->val);
        TreeNode* curr = root;
        while (true) {
            if (curr->val < min_val) {
                curr = curr->right;
            } else if (curr->val > max_val) {
                curr = curr->left;
            } else {
                return curr;
            }
        }
    }
};