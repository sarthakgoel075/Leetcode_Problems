class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        vector<pair<int,int>>v={{INT_MIN,-1},{INT_MIN,-1},{INT_MAX,-1},{INT_MAX,-1}};
        for(int i=0;i<arrays.size();i++){
                int s=arrays[i].size()-1;
                  if(arrays[i][s]>v[1].first){
                    v[0]=v[1];
                    v[1]={arrays[i][s],i};
                  }
                   else if (arrays[i][s] > v[0].first) {
                v[0] = {arrays[i][s], i}; // Update second max with current value
            }

                     if(arrays[i][0]<v[3].first){
                   v[2]=v[3];
                   v[3]={arrays[i][0],i};
                  }
                  else if (arrays[i][0] < v[2].first) {
                v[2] = {arrays[i][0], i}; // Update second min with current value
            }
          }
          if(v[1].second==v[3].second){
                return max((v[0].first-v[3].first),(v[1].first-v[2].first));
          }
          else{
            return v[1].first-v[3].first;
          }
        }
    
};