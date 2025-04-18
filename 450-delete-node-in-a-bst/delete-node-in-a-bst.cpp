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

    TreeNode * findLastRight(TreeNode * root){
        if(root == NULL){
            return root;
        }
        while(root->right != NULL){
            root = root->right;
        }
        return root;
    }

    TreeNode * solve(TreeNode * root){
        if(root->left == NULL){
            return root->right;
        }
        if(root->right == NULL){
            return root->left;
        }
        TreeNode * rightChild = root->right;
        TreeNode * lastRight = findLastRight(root->left);
        lastRight->right = rightChild;
        return root->left;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return NULL;
        }
        if(root->val == key){
            return solve(root);
        }
        TreeNode * dummy = root;
        while(root != NULL){
            if(root->val > key){
                if(root->left != NULL && root->left->val == key){
                    root->left = solve(root->left);
                }else{
                    root = root->left;
                }
            }else{
                if(root->right != NULL && root->right->val == key){
                    root->right = solve(root->right);
                }else{
                    root = root->right;
                }
            }
        }
        return dummy;
    }
};