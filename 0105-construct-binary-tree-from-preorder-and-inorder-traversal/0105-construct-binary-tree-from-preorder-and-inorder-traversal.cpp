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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> pos;

        for (int i = 0; i < inorder.size(); i++) {
            pos[inorder[i]] = i;
        }

        int preIndex = 0;

        function<TreeNode*(int, int)> helper = [&](int left, int right) -> TreeNode* {
            if (left > right) return nullptr;

            int rootVal = preorder[preIndex++];
            TreeNode* root = new TreeNode(rootVal);

            int mid = pos[rootVal];

            root->left = helper(left, mid - 1);
            root->right = helper(mid + 1, right);

            return root;
        };

        return helper(0, inorder.size() - 1);
    }
};