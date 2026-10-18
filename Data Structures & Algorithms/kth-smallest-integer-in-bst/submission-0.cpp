/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;

        int count = 0;

        inorder(root, ans, count, k);

        return ans[k - 1];
    }

    void inorder(TreeNode* root, vector<int>& ans, int& count, int k) {
        if (root == nullptr) {
            return;
        }

        inorder(root->left, ans, count, k);

        if (count >= k) {
            return;
        }

        ans.push_back(root->val);
        count++;
        
        inorder(root->right, ans, count, k);

    }
};
