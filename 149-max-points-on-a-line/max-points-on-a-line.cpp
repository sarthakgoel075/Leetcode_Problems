class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        int maxi=1;
        for(int i=0;i<n;i++){
            unordered_map<float,int>mp;
            int count=0;
            for(int j=0;j<n;j++){
             if(i==j)continue;
             if(points[i][0]==points[j][0]){
                mp[INT_MAX]++;
             }
             else{
                float slope=(float)((float)(points[j][1]-points[i][1])/(points[j][0]-points[i][0]));
                mp[slope]++;
             }
            }
            for (auto& [slope, count] : mp)
    maxi = max(maxi, count + 1);
        }
        return maxi;
    }
};