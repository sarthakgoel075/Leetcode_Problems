class Solution {
public:
    string solve(vector<string> &dummy, int size, int str, int maxsize) {
        int space = maxsize - size;
        string ans = "";
        
        if (str == 1) {
            // If there's only one word, just left-justify it
            ans = dummy[0];
            ans.append(space, ' ');
        } else {
            int evenSpace = space / (str - 1);
            int extraSpace = space % (str - 1);
            
            for (int i = 0; i < dummy.size(); i++) {
                ans += dummy[i];
                if (i != dummy.size() - 1) {
                    ans.append(evenSpace + (i < extraSpace ? 1 : 0), ' ');
                }
            }
        }
        return ans;
    }
    
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int i = 0;
        int n = words.size();
        vector<string> ans;
        vector<string> dummy;
        int size = 0;
        int str = 0;
        
        while (i < n) {
            if (size + words[i].length() + str <= maxWidth) {
                size += words[i].length();
                dummy.push_back(words[i]);
                str++;
                i++;
            } else {
                ans.push_back(solve(dummy, size, str, maxWidth));
                dummy.clear();
                size = 0;
                str = 0;
            }
        }
        
        // Handle the last line (left-justified)
        string last = "";
        for (int j = 0; j < dummy.size(); j++) {
            last += dummy[j];
            if (j != dummy.size() - 1) {
                last += " ";
            }
        }
        last.append(maxWidth - last.length(), ' ');
        ans.push_back(last);
        
        return ans;
    }
};
