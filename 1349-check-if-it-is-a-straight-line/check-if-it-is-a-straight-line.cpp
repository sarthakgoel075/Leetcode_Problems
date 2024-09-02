class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        // Calculate the initial slope between the first two points
        int x_diff = coordinates[1][0] - coordinates[0][0];
        int y_diff = coordinates[1][1] - coordinates[0][1];
        
        for (int i = 2; i < coordinates.size(); i++) {
            int x_diff_curr = coordinates[i][0] - coordinates[0][0];
            int y_diff_curr = coordinates[i][1] - coordinates[0][1];
            
            // Use cross multiplication to check for collinearity to avoid division and floating-point precision issues
            if (y_diff * x_diff_curr != x_diff * y_diff_curr) {
                return false;
            }
        }
        return true;
    }
};
