class Solution {
public:
    int fun(int n) {
        int ans = 0;
        while (n) {
            ans = ans + ((n % 10) * (n % 10));  // Correct squaring
            n /= 10;
        }
        return ans;
    }

    bool isHappy(int n) {
        unordered_set<int> seen;  // To detect cycles
        while (n != 1 && seen.find(n) == seen.end()) {
            seen.insert(n);
            n = fun(n);
        }
        return n == 1;
    }
};
