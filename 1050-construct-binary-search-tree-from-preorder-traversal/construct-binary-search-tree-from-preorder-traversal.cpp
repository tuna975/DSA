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

    TreeNode* f(vector<int>& a, int& i, int bd)
    {
        if(i == a.size() || a[i] > bd)
        {
            return NULL;
        }

        TreeNode* root = new TreeNode(a[i++]);
        root->left = f(a, i, root->val);
        root->right = f(a, i, bd);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return f(preorder, i, INT_MAX);
    }
};