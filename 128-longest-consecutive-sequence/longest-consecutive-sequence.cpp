#include <unordered_set>
#include <vector>
#include <algorithm>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
       
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;

        for (int num : s) {
           
            if (s.find(num - 1) == s.end()) {
                int curr_element = num;
                int count = 1;

               
                while (s.find(curr_element + 1) != s.end()) {
                    curr_element++;
                    count++;
                }

                ans = max(ans, count);
            }
        }

        return ans;
    }
};
