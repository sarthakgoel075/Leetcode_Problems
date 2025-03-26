class Solution {
public:
   int findparent(int i,vector<int>&parent){
        if(i==parent[i]){
            return i;
        }
        return parent[i]=findparent(parent[i],parent);
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
           vector<int>parent(n);
        vector<int>rank(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        int count=0;
        for(auto i:connections){
         int u=i[0];
         int v=i[1];
       
          int ulp_u=findparent(u,parent);
                    int ulp_v=findparent(v,parent);
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
        else{
            count++;
        }
        }
        int component=0;
        for(int i=0;i<n;i++){
            if(i==findparent(i,parent)){
                component++;
            }
        }
        component--;
       if(count>=component)return component;
       return -1;
    
    }
};