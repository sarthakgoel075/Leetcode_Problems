class Solution {
public:
    // Helper function to check if linked list is a subpath starting at current tree node
    bool fun(TreeNode* root, ListNode* head) {
        if (head == nullptr) return true; // If we've exhausted the linked list, path is found
        if (root == nullptr) return false; // If tree ends before list, return false

        // Check if current values match, and proceed with left or right subtree accordingly
        if (root->val == head->val) {
            return fun(root->left, head->next) || fun(root->right, head->next);
        }
        return false; // Mismatch, no valid path starting here
    }

    // Main function to check if any subpath exists
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (root == nullptr) return false; // If tree is empty, no path exists

        // Try to find subpath starting from the current node or any child node
        return fun(root, head) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};
