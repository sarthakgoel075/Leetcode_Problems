class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty()) return 0;  // Handle edge case where timeSeries is empty

        int finishtime = 0; // End time of the last poison
        int ans = 0; // Total poisoned duration

        for (int i = 0; i < timeSeries.size(); i++) {
            if (timeSeries[i] < finishtime) {
                // If the next poisoning starts before the previous one ends, only add the difference
                ans += timeSeries[i] + duration - finishtime;
            } else {
                // If no overlap, add the full duration
                ans += duration;
            }

            // Update the finish time of the last poison effect
            finishtime = timeSeries[i] + duration;
        }

        return ans;
    }
};
