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
        vector<vector<int>>ans;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int>curr;
            for(int i=0;i<n;i++){
              TreeNode* n=q.front();
              q.pop();
              if(n && n->left){
                q.push(n->left);
              }
              if(n && n->right){
                q.push(n->right);
              }
              if(n){
              curr.push_back(n->val);
              }
            }
            if(curr.size()>=1){
            ans.push_back(curr);
            }
        }
        return ans;
    }
};