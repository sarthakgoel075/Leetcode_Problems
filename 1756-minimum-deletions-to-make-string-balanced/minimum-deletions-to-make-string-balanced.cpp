class Solution {
public:
    int minimumDeletions(string s) {
        if (s.size() <= 1) return 0;
        
        vector<int> righta(s.size(), 0);
        int curra = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            righta[i] = curra;
            if (s[i] == 'a') curra++;
        }
        
        vector<int> leftb(s.size(), 0);
        int currb = 0;
        for (int i = 0; i <= s.size() - 1; i++) {
            leftb[i] = currb;
            if (s[i] == 'b') currb++;
        }
        
        int ans = INT_MAX;
        for (int i = 0; i < s.size(); i++) {
            ans = min(ans, leftb[i] + righta[i]);
        }
        
        return ans;
    }
};
