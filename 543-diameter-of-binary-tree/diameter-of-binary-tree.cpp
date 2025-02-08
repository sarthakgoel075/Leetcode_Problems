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
    int ans=0;
    int fun(TreeNode* root,int curr){
        if(root==NULL)return 0;
        int left=fun(root->left,curr+1);
        int right=fun(root->right,curr+1);
        ans=max(ans,right+left+1);
        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        fun(root,0);
        return ans-1;
    }
};