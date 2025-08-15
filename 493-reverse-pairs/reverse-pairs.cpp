class Solution {
public:
    int fun(vector<int>&nums,int low,int mid,int high){
         int count=0;
         int right=mid+1;
         for(int i=low;i<=mid;i++){
           while(right <= high && (long long)nums[i] > 2LL * nums[right]){
            right++;
           }
            count += (right - (mid + 1));
         }
         return count;
    }
    void merge(vector<int>&nums,int low,int high ,int mid){
      vector<int>temp;
      int right=mid+1;
      int left=low;
      while(left<=mid && right<=high){
        if(nums[left]<nums[right]){
            temp.push_back(nums[left]);
            left++;
        }
        else{
            temp.push_back(nums[right]);
            right++;
        }
      }
        while(left<=mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(nums[right]);
            right++;
        }
      for (int i = 0; i < temp.size(); i++) {
        nums[low + i] = temp[i];
    }
    }
    int mergesort(vector<int>&nums,int low,int high){
    
     if(low>=high)return 0;
     int mid=(low+high)/2;
    int count=mergesort(nums,low,mid);
    count+= mergesort(nums,mid+1,high);
    count+= fun(nums,low,mid,high);
     merge(nums,low,high,mid);
     return count;
    }
    int reversePairs(vector<int>& nums) {
       return  mergesort(nums,0,nums.size()-1);
    }
};