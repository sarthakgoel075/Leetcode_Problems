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
        bool a=true;
        bool b=true;
        if(p->val!=q->val)return false;
        if((p->left && q->left==NULL)|| (q->left && p->left==NULL))return false;
         if((p->right && q->right==NULL)|| (q->right && p->right==NULL))return false;

        if(p->left && q->left){
            a=fun(p->left,q->left);
            }
        if(p->right && q->right){
            b=fun(p->right,q->right);
            }
            return (a && b);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return fun(p,q);
    }
};