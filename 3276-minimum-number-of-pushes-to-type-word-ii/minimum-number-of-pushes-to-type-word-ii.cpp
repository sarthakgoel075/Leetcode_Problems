class Solution {
public:
    int minimumPushes(string word) {
        vector<int>v(26,0);
        for(auto i:word){
            v[i-'a']++;
        }
        sort(v.begin(),v.end(),[](auto a,auto b){
            return a>b;
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
          ans+=i*it;

         }
         return ans;
    }
};