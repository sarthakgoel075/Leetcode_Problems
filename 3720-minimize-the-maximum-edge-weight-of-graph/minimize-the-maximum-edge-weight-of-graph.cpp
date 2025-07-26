class Solution {
public:
    bool check(int i,vector<vector<pair<int,int>>>&adj,int n){
        vector<int>visited(n,0);
        queue<int>q;
        visited[0]=1;
        q.push(0);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                if(it.second<=i && !visited[it.first]){
                    q.push(it.first);
                    visited[it.first]=1;
                }
            }
        }
        for(auto it:visited){
            if(it==0)return false;
        }
        return true;
    }
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        vector<vector<pair<int,int>>>adj(n);
        int r=0;
        for(auto i:edges){
            adj[i[1]].push_back({i[0],i[2]});
            r=max(r,i[2]);
        }
        int result=INT_MAX;
        int l=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid,adj,n)){
                result=mid;
                r=mid-1;
            }
            else{
              l=mid+1;
            }
        }
        if(result==INT_MAX)return -1;
        else return result;
    }
};