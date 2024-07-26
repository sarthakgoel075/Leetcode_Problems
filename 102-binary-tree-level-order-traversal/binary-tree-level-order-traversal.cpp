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
        if(!root){
            return {};
        }
        queue<TreeNode* >q;
        q.push(root);
        vector<vector<int>>ans;
        while(!q.empty()){
            vector<int>curr;
            int n=q.size();
         for(int i=0;i<n;i++){
             TreeNode*temp=q.front();
             q.pop();
             curr.push_back(temp->val);
            if(temp->left) {q.push(temp->left);}
            if(temp->right) {q.push(temp->right);}
         }
         ans.push_back(curr);
        }
        return ans;
    }
};