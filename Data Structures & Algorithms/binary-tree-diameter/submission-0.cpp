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
    int diameter = 0;

    int height(TreeNode* root) {

        if (root == nullptr)
            return 0;

        // Get height of left subtree
        int left = height(root->left);

        // Get height of right subtree
        int right = height(root->right);

        // Diameter passing through this node
        diameter = max(diameter, left + right);

        // Return height of this node
        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {

        height(root);

        return diameter;
    }
};
