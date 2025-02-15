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
class BSTIterator {
public:
    vector<int>store;
    int i=0;
    BSTIterator(TreeNode* root) {
       fun(root);
    }
    void fun(TreeNode* root){
        if(root==NULL)return ;
        if(root->left)fun(root->left);
        store.push_back(root->val);
        if(root->right)fun(root->right);

    }
    
    int next() {
        return store[i++];
    }
    
    bool hasNext() {
        return i<store.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */