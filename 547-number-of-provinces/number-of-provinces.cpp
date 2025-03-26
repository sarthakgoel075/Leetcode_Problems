class Solution {
public:
    int findparent(int i,vector<int>&parent){
        if(i==parent[i]){
            return i;
        }
        return parent[i]=findparent(parent[i],parent);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>parent(n);
        vector<int>rank(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isConnected[i][j]==1){
                    int ulp_u=findparent(i,parent);
                    int ulp_v=findparent(j,parent);
                    if(ulp_u!=ulp_v){
                        if(rank[ulp_u]<rank[ulp_v]){
                            parent[ulp_u]=ulp_v;
                        }
                        else if(rank[ulp_u]>rank[ulp_v]){
                            parent[ulp_v]=ulp_u;
                        }
                        else{
                            parent[ulp_v]=ulp_u;
                            rank[ulp_u]++;
                        }
                    }
                }
            }
        }
        set<int>s;
        for(int i=0;i<n;i++){
            s.insert(findparent(i,parent));
        }
        return s.size();
    }
};