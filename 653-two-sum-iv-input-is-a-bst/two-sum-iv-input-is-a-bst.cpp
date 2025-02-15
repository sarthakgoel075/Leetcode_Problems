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
       vector<int>arr;
    void fun(TreeNode* root){
        if(root==NULL)return ;
        if(root->left)fun(root->left);
        arr.push_back(root->val);
        if(root->right)fun(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL)return false;
        fun(root);
        if(arr.size()==1)return false;
        int left=0;
        int right=arr.size()-1;
        while(left<=right){
             if(arr[left]+arr[right]==k  && left!=right)return true;
            if((arr[left]+arr[right])<k)left++;
            else{
                right--;
            }
        }
        return false;
    }
};