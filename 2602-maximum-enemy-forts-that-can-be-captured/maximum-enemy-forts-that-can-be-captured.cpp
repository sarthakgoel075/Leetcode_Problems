class Solution {
public:
    int captureForts(vector<int>& forts) {
        int ans = 0;
        int cnt = 0;
        int n = forts.size();
        
        for (int i = 0; i < n; ++i) {
            if (forts[i] == 0) {
                cnt++;
            } else {
                if (cnt > 0) {
                    // Check if we have 1 (friendly fort) on the left and -1 (enemy fort) on the right or vice versa
                    if (i - cnt - 1 >= 0 && 
                        ((forts[i - cnt - 1] == 1 && forts[i] == -1) || 
                         (forts[i - cnt - 1] == -1 && forts[i] == 1))) {
                        ans = max(ans, cnt);
                    }
                }
                cnt = 0; // Reset count for the next sequence
            }
        }
        
        return ans;
    }
};
