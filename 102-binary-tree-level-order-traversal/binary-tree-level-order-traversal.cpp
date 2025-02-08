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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        while(!q.empty()){
           int size=q.size();
           vector<int>curr;
           for(int i=0;i<size;i++){
            auto t=q.front();
            q.pop();
           curr.push_back(t->val);
           if(t->left)q.push(t->left);
           if(t->right)q.push(t->right);
           }
           ans.push_back(curr);
        }
        return ans;
    }
};