class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int>mp;
        for(auto i:word){
            mp[i]++;
        }
        vector<pair<int,int>>v(mp.begin(),mp.end());
        sort(v.begin(),v.end(),[](auto a,auto b){
            return a.second>b.second;
        });
        int ans=0;
        int count=0;
        int i=1;
         for(auto it:v){
          count++;
          if(count>8){
            i++;
            count=1;
          }
          ans+=i*it.second;

         }
         return ans;
    }
};