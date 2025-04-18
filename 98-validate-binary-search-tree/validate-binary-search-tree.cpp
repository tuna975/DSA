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

    bool f(TreeNode* root, long long l, long long h)
    {
        if(root == NULL)
        {
            return true;
        }

        if(root->val >= h || root->val <= l)
        {
            return false;
        }

        return f(root->left, l, root->val) && f(root->right, root->val, h);
    }


    bool isValidBST(TreeNode* root) {
        long long l = LLONG_MIN;
        long long h = LLONG_MAX;
        return f(root, l, h);
    }
};