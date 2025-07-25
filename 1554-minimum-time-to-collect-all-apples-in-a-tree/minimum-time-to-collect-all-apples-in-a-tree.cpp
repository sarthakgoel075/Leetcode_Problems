class Solution {
public:
    int dfs(vector<vector<int>>&adj,int i,int parent,vector<bool>&hasApple){
        int curr=0;
        for(auto it:adj[i]){
            if(it==parent)continue;
            curr+=dfs(adj,it,i,hasApple);
        }
        if(curr==0 && hasApple[i]==false)return 0;
        else return 2+curr;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        queue<int>q;
        vector<vector<int>>adj(n);
        int level=0;
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        int ans= dfs(adj,0,-1,hasApple);
        if(ans>0)return ans-2;
        else return  ans;
    }
};