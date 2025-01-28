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
    class info{
        public:
        int maxi;
        int mini;
        bool is_bst;
        int sum;
    };
    info fun(TreeNode*root,int &maxsum){
    if(root==NULL){
        return {INT_MIN,INT_MAX,true,0};
    }
    info left=fun(root->left,maxsum);
    info right=fun(root->right,maxsum);
    info curr;
    curr.maxi=max(root->val,right.maxi);
    curr.mini=min(root->val,left.mini);
    curr.sum=root->val+left.sum+right.sum;
    if(root->val>left.maxi && root->val<right.mini && (left.is_bst && right.is_bst)){
        curr.is_bst=true;
        maxsum=max(maxsum,curr.sum);
    }
    else{
        curr.is_bst=false;
    }
    return curr;
    }
    int maxSumBST(TreeNode* root) {
        int maxsum=0;
        info ans=fun(root,maxsum);
        return maxsum;
    }
};