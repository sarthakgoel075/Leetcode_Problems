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
    int fun(TreeNode* root,unordered_map<TreeNode *,int>&dp){
        if(!root)return 0;
        if(dp.count(root))return dp[root];
        int take=root->val;
        int nottake=0;
        if(root->left && root->left->left){
            take+=fun(root->left->left,dp);
        }
        if(root->left && root->left->right){
            take+=fun(root->left->right,dp);
        }
        if(root->right && root->right->left){
            take+=fun(root->right->left,dp);
        }
        if(root->right && root->right->right){
            take+=fun(root->right->right,dp);
        }
        if(root->left){
            nottake+=fun(root->left,dp);
        }
        if(root->right){
            nottake+=fun(root->right,dp);
        }
        return dp[root]=max(take,nottake);
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode *,int>dp;
        return fun(root,dp);
    }
};