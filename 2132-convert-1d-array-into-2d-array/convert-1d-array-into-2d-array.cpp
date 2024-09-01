class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>ans(m,vector<int>(n));
         int size = original.size();
        if(size!=m*n)          //if the original cannot fit in m*n 2d matrix, return null
            return {};
        int row=0;
        int col=0;
        for(auto i:original){
            ans[row][col]=i;
            col++;
            if(col==n){
                col=0;
                row++;
            }
        }
        return ans;
    }
};