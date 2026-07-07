class Solution {
public:
    int mini=INT_MAX;
    void fun(int left,int right,int h,vector<int>&piles){
        if (left>right) return ;
        int mid = (left+right)/2;
        long long total=0;
        for(auto i:piles){
            if(i<=mid){
                total+=1;
            }
            else{
               total += (i + mid - 1) / mid;
            }}
            if(total<=h){
                mini=min(mini,mid);
                fun(left,mid-1,h,piles);
            }
            else{
                fun(mid+1,right,h,piles);
            }
        }

    int minEatingSpeed(vector<int>& piles, int h) {
      int maxi=INT_MIN;
      for(auto i:piles){
        maxi=max(maxi,i);
      }
      int n=piles.size()-1;
      fun(1,maxi,h,piles);
      return mini;
    }
};