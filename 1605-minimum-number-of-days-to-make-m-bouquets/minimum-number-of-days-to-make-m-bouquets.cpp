class Solution {
public:
    bool check(int day,vector<int>&bloomDay,int m,int k){
        int curr=0;
        int num=0;
        int pre=-1;
        for(auto i:bloomDay){
          if(i<=day){
            curr++;
          }
          else{
            num+=curr/k;
            curr=0;
          }
        }
         num += curr / k;
        return num>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int lower=INT_MAX;
        int high=INT_MIN;
        for(auto i:bloomDay){
          lower=min(lower,i);
          high=max(high,i);
        }
        int ans=INT_MAX;
        while(lower<=high){
            int mid=(lower+high)/2;
            if(check(mid,bloomDay,m,k)){
                ans=min(mid,ans);
                high=mid-1;
            }
            else{
                lower=mid+1;
            }
        }
       if(ans==INT_MAX)return -1;
       return ans;
    }
};