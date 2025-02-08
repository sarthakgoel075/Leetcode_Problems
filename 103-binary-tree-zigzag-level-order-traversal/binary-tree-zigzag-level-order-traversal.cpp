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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        queue<TreeNode*>q;
        q.push(root);
        int temp=1;
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
               if(temp==-1){
                reverse(curr.begin(),curr.end());
               }
               ans.push_back(curr);
               temp*=-1;
        }
        return ans;
    }
};