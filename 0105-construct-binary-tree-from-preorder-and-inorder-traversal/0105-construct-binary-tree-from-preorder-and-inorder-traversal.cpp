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
    unordered_map<int, int> index;
    int preIndex = 0;

    TreeNode* helper(vector<int>& preorder, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        int rootValue = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootValue);

        int mid = index[rootValue];

        root->left = helper(preorder, left, mid - 1);
        root->right = helper(preorder, mid + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            index[inorder[i]] = i;
        }

        return helper(preorder, 0, inorder.size() - 1);
    }
};