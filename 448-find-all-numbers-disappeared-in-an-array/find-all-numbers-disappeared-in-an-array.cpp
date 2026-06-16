class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int pos=abs(nums[i])-1;
            if(nums[pos]>0){
                nums[pos]=nums[pos]*-1;
            }
        }
        vector<int>v;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                v.push_back(i+1);
            }
        }
        return v;
    }
};