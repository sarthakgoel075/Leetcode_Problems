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
    bool helpr(TreeNode* root,long long a,long long b){
        if(!root)return true;
        if(root->val>=a || root->val<=b){
         return false;
        }
        return helpr(root->left,root->val,b)  && helpr(root->right,a,root->val);
    }
    bool isValidBST(TreeNode* root) {
        return helpr(root,LONG_MAX,LONG_MIN);
    }
};