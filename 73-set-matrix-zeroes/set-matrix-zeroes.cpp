class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>row(n,0);
        vector<int>col(m,0);
        vector<vector<int>>v(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    if(row[i]==0){
                        for(int k=0;k<m;k++){
                            v[i][k]=0;
                        }
                        row[i]=1;
                    }
                     if(col[j]==0){
                        for(int k=0;k<n;k++){
                            v[k][j]=0;
                        }
                        col[j]=1;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]!=0){
                    v[i][j]=matrix[i][j];
                }
            }
        }
        matrix=v;
       
    }
};