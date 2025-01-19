class Solution {
public:
    vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n=heightMap.size();
        int m=heightMap[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        for(int i=0;i<n;i++){
            for(int j:{0,m-1}){
                pq.push({heightMap[i][j],{i,j}});
                 visited[i][j] = 1;
            }
        }
          for(int j=0;j<m;j++){
            for(int i:{0,n-1}){
                pq.push({heightMap[i][j],{i,j}});
                 visited[i][j] = 1;
            }
        }
        int water=0;
        while(!pq.empty()){
           auto node=pq.top();
           pq.pop();
           int i=node.second.first;
           int j=node.second.second;
           int h=node.first;
           for(int k=0;k<4;k++){
            int i_=i+dir[k][0];
            int j_=j+dir[k][1];
            if(i_>=0 && i_<n && j_>=0 && j_<m && visited[i_][j_]!=1){
                visited[i_][j_]=1;
                water+=max(0,h-heightMap[i_][j_]);
             pq.push({max(h, heightMap[i_][j_]), {i_, j_}});
            }
           }
        }
       return water;
    }
};