class Solution {
public:
    void fun(vector<int>& candidates, int target, int sum, int ind, vector<vector<int>>& ans, vector<int>& curr) {
        if (sum == target) {
            ans.push_back(curr);
            return;
        }
        for (int i = ind; i < candidates.size(); i++) {
            if (i > ind && candidates[i] == candidates[i - 1]) continue; // Skip duplicates
            if (sum + candidates[i] > target) break; // No need to continue if sum exceeds target
            curr.push_back(candidates[i]);
            fun(candidates, target, sum + candidates[i], i + 1, ans, curr); // Move to next index
            curr.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(candidates.begin(), candidates.end()); // Sort to handle duplicates
        fun(candidates, target, 0, 0, ans, curr);
        return ans;
    }
};
