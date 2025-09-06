class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i=0;
        while(true){
        if(nums[i]<0)return i;
        else {
            int temp=nums[i];
            nums[i]=-1;
            i=temp;
        }
        }

    }
};