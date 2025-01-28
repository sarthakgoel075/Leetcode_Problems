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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.empty()) return nullptr;

        TreeNode* root = new TreeNode(preorder[0]); 
        stack<TreeNode*> s; 
        s.push(root);
        for(int i=1;i<preorder.size();i++){
            TreeNode* curr = new TreeNode(preorder[i]);
            if(preorder[i]<s.top()->val){
                s.top()->left=curr;
            }
            else{
                   TreeNode* child = nullptr;
                while (!s.empty() && s.top()->val < preorder[i]) {
                    child = s.top();
                    s.pop();
                }
                 child->right = curr;
            
            }
            s.push(curr);
        }
        return root;
    }
};