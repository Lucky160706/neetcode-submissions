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
    int goodNodes(TreeNode* root) {
        if (root == nullptr) return 0;

        dfs(root, root->val);
        return ans;
    }

    void dfs(TreeNode* root, int maxSoFar) {
        if (root == nullptr) return ;

        if (root->val >= maxSoFar) {
            ans++;
        }

        maxSoFar = max(maxSoFar, root->val);

        dfs(root->left, maxSoFar);
        dfs(root->right, maxSoFar);
    }

private:
    int ans = 0;
};
