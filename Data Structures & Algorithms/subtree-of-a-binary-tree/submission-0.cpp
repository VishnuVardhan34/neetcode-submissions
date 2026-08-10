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

    // Check whether two trees are exactly the same
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // Both are NULL
        if (p == nullptr && q == nullptr)
            return true;

        // One is NULL, other isn't
        if (p == nullptr || q == nullptr)
            return false;

        // Values are different
        if (p->val != q->val)
            return false;

        // Both left and right subtrees must match
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        // If root becomes NULL, we didn't find subRoot
        if (root == nullptr)
            return false;

        // Check if current tree matches subRoot
        if (isSameTree(root, subRoot))
            return true;

        // Search in left and right subtrees
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};
