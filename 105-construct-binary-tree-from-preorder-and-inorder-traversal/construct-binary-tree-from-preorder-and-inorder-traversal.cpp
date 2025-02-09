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
    TreeNode* fun(unordered_map<int,int>&mp,vector<int>&preorder,int prestart,int preend, vector<int>& inorder,int instart,int inend){
        if(prestart>preend || instart>inend)return NULL;
        TreeNode* curr=new TreeNode(preorder[prestart]);
        int ind=mp[preorder[prestart]];
        int num=ind-instart;
        curr->left=fun(mp,preorder,prestart+1,prestart+num,inorder,instart,ind-1);
        curr->right=fun(mp,preorder,prestart+num+1,preend,inorder,ind+1,inend);
        return curr;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        int n=preorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        return fun(mp,preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
};