class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
       vector<vector<int>>mat(n+1,vector<int>(n+1,0));
       int ans=-1;
       for(auto i:trust){
        mat[i[0]][i[1]]=1;
       }
       for(int i=1;i<n+1;i++){
        int flag=0;
        for(int j=1;j<n+1;j++){
            if(mat[i][j]==1){
                flag=1;
                break;
            }
        }
        
        if(flag==0){
            int t=0;
            for(int k=1;k<=n;k++){
                if( k!=i && mat[k][i]!=1){
                    t=1;
                    break;
                }
            }
           if(t==0){
             return i;
           }
        }
       }
       return ans;
    }
};