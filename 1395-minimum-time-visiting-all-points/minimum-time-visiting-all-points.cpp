class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans=0;
        int x=points[0][0];
        int y=points[0][1];
        for(int i=1;i<points.size();i++){
           int curr=0;
           int x_diff=abs(x-points[i][0]);
           int y_diff=abs(y-points[i][1]);
           curr=max(x_diff,y_diff);
            ans+=curr;
            x=points[i][0];
            y=points[i][1];
        }
        return ans;
    }
};