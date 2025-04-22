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
    int rightmost=0;
    int leftmost=0;
    void fun(TreeNode* root,int t,int h,unordered_map<int,vector<pair<int,int>>>&mp){
        mp[t].push_back({h,root->val});
        leftmost=min(t,leftmost);
        rightmost=max(t,rightmost);
       if(root->left)fun(root->left,t-1,h+1,mp);
       if(root->right)fun(root->right,t+1,h+1,mp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        unordered_map<int,vector<pair<int,int>>>mp;
        fun(root,0,0,mp);
        vector<vector<int>>ans;
        for(int i=leftmost;i<=rightmost;i++){
            sort(mp[i].begin(),mp[i].end(),[](const auto a,const auto b){
                if(a.first==b.first){
                   return a.second<b.second;
                }
                else{
                return a.first<b.first;}
            });
            vector<int>curr;
            for(auto it:mp[i]){
                curr.push_back(it.second);
            }
            ans.push_back(curr);
        }
        return ans;
    }
};