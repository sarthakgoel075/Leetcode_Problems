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
    vector<int> fun(TreeNode* root){
        if(root==NULL)return {0,0};
        vector<int>left=fun(root->left);
        vector<int>right=fun(root->right);
        int curr=left[1]+right[1];
        int maxi=max(left[0],max(right[0],curr));
        return {maxi,1+max(left[1],right[1])};
    }
    int diameterOfBinaryTree(TreeNode* root) {
       vector<int>ans=fun(root);
       return ans[0];
    }
};