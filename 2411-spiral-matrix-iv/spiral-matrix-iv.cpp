/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1)); // Correct matrix dimensions
        int top = 0, bottom = m - 1, left = 0, right = n - 1; // Define boundaries
        while (head && top <= bottom && left <= right) {
            // Traverse from left to right
            for (int j = left; j <= right && head; j++) {
                ans[top][j] = head->val;
                head = head->next;
            }
            top++; // Move the top boundary down
            
            // Traverse from top to bottom
            for (int i = top; i <= bottom && head; i++) {
                ans[i][right] = head->val;
                head = head->next;
            }
            right--; // Move the right boundary left
            
            // Traverse from right to left
            if (top <= bottom) {
                for (int j = right; j >= left && head; j--) {
                    ans[bottom][j] = head->val;
                    head = head->next;
                }
                bottom--; // Move the bottom boundary up
            }
            
            // Traverse from bottom to top
            if (left <= right) {
                for (int i = bottom; i >= top && head; i--) {
                    ans[i][left] = head->val;
                    head = head->next;
                }
                left++; // Move the left boundary right
            }
        }
        return ans;
    }
};
