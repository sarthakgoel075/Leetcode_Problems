class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans = 0;
        int left = 0;
        int right = 0;
        int n = nums.size();
        priority_queue<pair<int, int>> pq1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq2;
        while (right < n) {
            pq1.push({nums[right], right});
            pq2.push({nums[right], right});
            while ((pq1.top().first - pq2.top().first) > limit) {
                left = min(pq1.top().second, pq2.top().second) + 1;
                while (pq1.top().second < left)
                    pq1.pop();

                while (pq2.top().second < left)
                    pq2.pop();

            }
                            ans = max(ans, right - left + 1);

                            right++;

        }
        return ans;
    }
};