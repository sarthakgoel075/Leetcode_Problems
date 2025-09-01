class Solution {
public:
    bool check(int mid,vector<int>&piles,int h){
        long long  curr=0;
        for(auto i:piles){
            curr+=i/mid;
            if(i%mid!=0)curr++;
        }
        return curr<=(long long)h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int lower=1;
        int high=0;
        
        for(auto i:piles){
            high=max(high,i);
        }
        int ans=high;
        while(lower<=high){
            int mid=(lower+high)/2;
            if(check(mid,piles,h)){
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