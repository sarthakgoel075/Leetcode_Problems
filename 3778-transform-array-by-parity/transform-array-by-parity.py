class Solution(object):
    def transformArray(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        for i,j in enumerate (nums):
            if j%2==0:
                nums[i]=0
            else:
                nums[i]=1
        ind=0
        lastind=len(nums)
        for i in nums:
            if(i==0):
                nums[ind]=0
                ind=ind+1
        while ind<lastind:
            nums[ind]=1
            ind=ind+1

        
        return nums 
        
        