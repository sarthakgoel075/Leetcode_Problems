class Solution {
public:
    bool check(int maxweight,vector<int>& weights, int days){
        int day=0;
        int curr=0;
        for(auto i:weights){
            if(curr+i>maxweight){
              day++;
              curr=i;
            }
            else{
                curr+=i;
            }
        }
        day++;
        return day<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int lower=0;
        for(auto i:weights){
            lower=max(lower,i);
        }
        int high=INT_MAX;
        int ans=INT_MAX;
        while(lower<=high){
            int mid=lower+(high-lower)/2;
            if(check(mid,weights,days)){
                ans=min(ans,mid);
                high=mid-1;
            }
            else{
                lower=mid+1;
            }
        }
        return ans;
    }
};