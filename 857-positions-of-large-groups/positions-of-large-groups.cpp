class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        if (s.size() < 3) return ans;

        int startind = 0; // Start index of a potential large group
        int count = 1; // Count the number of repeating characters

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                // If the current character is the same as the previous one, increase the count
                count++;
            } else {
                // If characters are different and the count of the previous group is >= 3
                if (count >= 3) {
                    ans.push_back({startind, i - 1}); // Add the start and end indices to the answer
                }
                // Reset for the next potential group
                startind = i; // Start a new group from the current index
                count = 1; // Reset count to 1 for the new character
            }

            // Final check at the end of the string to see if the last group is large
            if (i == s.size() - 1 && count >= 3) {
                ans.push_back({startind, i}); // End index is the last index `i`
            }
        }

        return ans;
    }
};
