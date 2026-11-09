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
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,
                    int preStart, int preEnd,
                    int inStart, int inEnd,
                    unordered_map<int, int>& pos) {
        
        if (preStart > preEnd) {
            return nullptr;
        }

        // Step 1: Find the root
        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        // Step 2: Find root in inorder
        int mid = pos[rootVal];

        // Step 3: Count nodes in left subtree
        int leftSize = mid - inStart;

        // Step 4: Build left subtree
        root->left = helper(
            preorder, inorder,
            preStart + 1,
            preStart + leftSize,
            inStart,
            mid - 1,
            pos
        );

        // Step 5: Build right subtree
        root->right = helper(
            preorder, inorder,
            preStart + leftSize + 1,
            preEnd,
            mid + 1,
            inEnd,
            pos
        );

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();

        unordered_map<int, int> pos;

        for (int i = 0; i < n; i++) {
            pos[inorder[i]] = i;
        }

        return helper(preorder, inorder,
                      0, n - 1,
                      0, n - 1,
                      pos);

    }
};
