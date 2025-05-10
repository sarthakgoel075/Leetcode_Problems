class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1=0;
        long long sum2=0;
        long long zero1=0;
        long long zero2=0;
        for(auto i:nums1){
            if(i==0)zero1++;
            sum1+=i;
        }
        for(auto i:nums2){
            if(i==0)zero2++;
            sum2+=i;
        }
        sum1+=zero1;
        sum2+=zero2;
        if((sum1)>(sum2)){
            if(zero2>0)return sum1;
            else{
                return -1;
            }
        }
        else if(sum2>sum1){
            if(zero1>0)return sum2;
            else{
                return -1;
            }
        }
        else{
            return sum1;
        }

     return -1;
    }
};