class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<vector<int>>arr;
            for(int i=0;i<nums.size();i++){
                arr.push_back({nums[i],i});
            }
        sort(arr.begin(),arr.end());
        int l=0;
        int r=nums.size()-1;
        while(l<r){
            if(arr[l][0]+arr[r][0]==target)return {arr[l][1],arr[r][1]};
            else if(arr[l][0]+arr[r][0]<target){
                l++;
            }
            else{
                r--;
            }
        }
        return {arr[l][1],arr[r][1]};
    }
};