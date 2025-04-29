class Solution {
public:
    int findparent(vector<int>&parent,int i){
        if(parent[i]!=i){
            parent[i]=findparent(parent,parent[i]);
        }
        return parent[i];
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<pair<int,pair<int,int>>>arr;
        int n=points.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int w=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                arr.push_back({w,{i,j}});
            }
        }
        sort(arr.begin(),arr.end());
        vector<int>parent(n);
        vector<int>rank(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        int ans=0;
        for(int i=0;i<arr.size();i++){
            int w=arr[i].first;
            int u=arr[i].second.first;
            int v=arr[i].second.second;
            int p_u=findparent(parent,u);
            int p_v=findparent(parent,v);
            if(p_u!=p_v){
                if(rank[p_u]>rank[p_v]){
                    parent[p_v]=p_u;
                }
                else if(rank[p_v]>rank[p_u]){
                    parent[p_u]=p_v;
                }
                else {
                    parent[p_v]=p_u;
                    rank[p_u]++;
                }
                ans+=w;
            }
        }
        return ans;
    }
};