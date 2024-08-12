class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = words.size();
        int m = words[0].size();
        int len = n * m;
        vector<int> ans;

        if (s.length() < len) return ans;
        unordered_map<string, int> wordCount;
        for (const string& word : words) {
            wordCount[word]++;
        }

        // Sliding window
        for (int i = 0; i < m; i++) {
            unordered_map<string, int> currentCount;
            int l = i, r = i, count = 0;

            while (r + m <= s.length()) {
                string word = s.substr(r, m);
                r += m;

                if (wordCount.find(word) != wordCount.end()) {
                    currentCount[word]++;
                    count++;

                    while (currentCount[word] > wordCount[word]) {
                        string leftWord = s.substr(l, m);
                        currentCount[leftWord]--;
                        count--;
                        l += m;
                    }

                    if (count == n) {
                        ans.push_back(l);
                    }
                } else {
                    currentCount.clear();
                    count = 0;
                    l = r;
                }
            }
        }

        return ans;
    }
};
