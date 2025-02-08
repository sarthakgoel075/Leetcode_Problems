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
bool fun(TreeNode* p, TreeNode* q){
         if(p==NULL && q==NULL)return true;
        if((p==NULL && q!=NULL)  || (q==NULL  && p!=NULL))return false;
        if(p->val !=q->val)return false;
        bool a=true;
        bool b=true;
        if((p->left && q->right==NULL)|| (q->right && p->left==NULL))return false;
         if((p->right && q->left==NULL)|| (q->left && p->right==NULL))return false;

        if(p->left && q->right){
            a=fun(p->left,q->right);
            }
        if(p->right && q->left){
            b=fun(p->right,q->left);
            }
            return (a && b);
    }
    bool isSymmetric(TreeNode* root) {
        return fun(root->left,root->right);
    }
};