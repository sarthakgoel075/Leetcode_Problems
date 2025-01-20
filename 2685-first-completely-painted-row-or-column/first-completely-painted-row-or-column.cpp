class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,pair<int,int>>mp;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[mat[i][j]]={i,j};
            }
        }
        vector<int>row(n,0);
        vector<int>col(m,0);
        for(int i=0;i<arr.size();i++){
            int curr=arr[i];
            int r=mp[curr].first;
            int c=mp[curr].second;
            row[r]++;
            if(row[r]==m)return i;
            col[c]++;
            if(col[c]==n)return i;
        }
        return 0;
    }
};