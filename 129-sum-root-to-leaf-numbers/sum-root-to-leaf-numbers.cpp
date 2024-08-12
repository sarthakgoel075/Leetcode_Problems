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
    int sum=0;
    void fun(TreeNode* root,int t){
        if(root==NULL)return ;
        int data=(t*10)+root->val;
        if(!root->left && !root->right){
            sum+=data;
        }
        if(root->left){
            fun(root->left,data);
        }
        if(root->right){
            fun(root->right,data);
        }
    }
    int sumNumbers(TreeNode* root) {
        fun(root,0);
        return sum;
    }
};