class Solution {
public:
      
    priority_queue<int>pq;
    bool checkbound(vector<pair<int,int>>&vertex,vector<vector<int>>& grid){
        for(auto i:vertex){
            int a=i.first;
            int b=i.second;
            if(a<0|| b<0|| a>=grid.size()|| b>=grid[0].size())return false;
        }
        return true;
    }

    bool getallvertex(vector<vector<int>>& grid,int i,int j,vector<pair<int,int>>&vertex,int len){
        pair<int,int>center(i,j);
 
        pair<int,int>A(i-len,j);
        pair<int,int>B(i,j+len);
        pair<int,int>C(i+len,j);
        pair<int,int>D(i,j-len);
        vertex.clear();
        vertex.push_back(A);
           vertex.push_back(B);
              vertex.push_back(C);
                 vertex.push_back(D);
        if(checkbound(vertex,grid)){
            return true;
        }
        else{
            return false;
        }

    }
    void findarea(vector<vector<int>>& grid,int i,int j){
       pq.push(grid[i][j]);
       int len=1;
       vector<pair<int,int>>vertex;
       while(getallvertex(grid,i,j,vertex,len)){
         int vertexsum=0;
          pair<int,int>A=vertex[0];
           pair<int,int>B=vertex[1];
            pair<int,int>C=vertex[2];
             pair<int,int>D=vertex[3];
           vertexsum= grid[A.first][A.second]+ grid[B.first][B.second]+ grid[C.first][C.second]+ grid[D.first][D.second];
           int btwlen=B.first-A.first;
           int btwsum=0;
           for(int step=1;step<btwlen;step++){
                btwsum += grid[A.first + step][A.second + step];   // A → B
    btwsum += grid[B.first + step][B.second - step];   // B → C
    btwsum += grid[C.first - step][C.second - step];   // C → D
    btwsum += grid[D.first - step][D.second + step];   // D → A
                //A se b ka
                // btwsum+=grid[A.first+i][B.second-i];
                // btwsum+=grid[B.first+i][C.second+i];
                // btwsum+=grid[C.first-i][D.second+i];
                // // btwsum+=grid[A.first+i][D.second+i];
                //  btwsum += grid[D.first - i][D.second + i];  // D to A
           }
           int finalsum=vertexsum+btwsum;
           pq.push(finalsum);
           len++;
       }
    }
    bool issame(vector<int>&ans,int checkval){
        for(auto n : ans){
            if(checkval==n)return true;
        }
        return false;
    }
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        vector<int>ans;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               findarea(grid,i,j);
            }
        }

        while(!pq.empty() && ans.size()<3){
            auto topp=pq.top();
            pq.pop();
            if(issame(ans,topp)==false){
                ans.push_back(topp);
            }
        }
        return ans;
    }
};