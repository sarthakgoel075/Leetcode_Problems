class Solution {
public:
    int fun(TreeNode* root, int &maxi) {

        if(!root->left && !root->right)
            return 1;

        int l = 0;
        if(root->left)
            l = fun(root->left, maxi);

        int r = 0;
        if(root->right)
            r = fun(root->right, maxi);

        maxi = max(maxi, l + r);

        return max(l, r) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {

        if(root == nullptr)
            return 0;

        int maxi = 0;
        fun(root, maxi);

        return maxi;
    }
};