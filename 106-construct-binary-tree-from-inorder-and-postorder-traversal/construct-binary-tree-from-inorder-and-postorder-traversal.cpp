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
    TreeNode* fun(unordered_map<int,int>&mp,vector<int>& inorder,int instart,int inend, vector<int>& postorder,int poststart,int postend){
        if(poststart>postend || instart>inend)return NULL;
        TreeNode* curr=new TreeNode(postorder[postend]);
        int ind=mp[postorder[postend]];
        int num=ind-instart;
        curr->left=fun(mp,inorder,instart,ind-1,postorder,poststart,poststart+num-1);
        curr->right=fun(mp,inorder,ind+1,inend,postorder,poststart+num,postend-1);
        return curr;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mp;
        int n=inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        return fun(mp,inorder,0,n-1,postorder,0,n-1);
    }
};