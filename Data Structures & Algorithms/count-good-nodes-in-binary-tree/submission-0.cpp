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

        arr.push_back(root->val);

        dfs(root);
        return ans;
    }

    void dfs(TreeNode* root) {
        if (root == nullptr) return ;

        int cnt = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= root->val) {
                cnt++;
            }
        }

        if (cnt == arr.size()) ans++;

        arr.push_back(root->val);

        dfs(root->left);
        dfs(root->right);

        arr.pop_back();
    }

private:
    int ans = 0;
    vector<int> arr;

};
