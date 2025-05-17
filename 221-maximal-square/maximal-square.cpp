class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=0;
        vector<vector<int>>temp(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            temp[0][i]=matrix[0][i]-'0';
            ans=max(ans,temp[0][i]);
        }
        for(int i=0;i<n;i++){
            temp[i][0]=matrix[i][0]-'0';
            ans=max(ans,temp[i][0]);
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]=='1'){
                int mini=min(temp[i-1][j-1],min(temp[i-1][j],temp[i][j-1]));
                temp[i][j]=mini+1;
                ans=max(ans,temp[i][j]);
                }
            }
        }
        return ans*ans;
    }
};