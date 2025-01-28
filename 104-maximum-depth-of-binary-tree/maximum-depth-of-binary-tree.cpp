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
    int fun(TreeNode* root,int curr){
        int left=0;
        int right=0;
        if(root==NULL)return 0;
        if(root->left){
          left=  fun(root->left,curr+1);
        }
        if(root->right){
            right=fun(root->right,curr+1);
        }
        return max(curr,max(left,right));
    }
    int maxDepth(TreeNode* root) {
        return fun(root,1);        
    }
};