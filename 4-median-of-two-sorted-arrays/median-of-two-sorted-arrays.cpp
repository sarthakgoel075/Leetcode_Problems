class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

         int n1=nums1.size();
         int n2=nums2.size();
         if(n2<n1)return findMedianSortedArrays(nums2,nums1);
         int low=0;
         int high=n1;
         while(low<=high){
            int mid=(low+high)/2;
            double l1=INT_MIN;
            double l2=INT_MIN;
            double r1=INT_MAX;
            double r2=INT_MAX;
            double mid2=((n1+n2)/2)-mid;
            if(mid-1>=0 && mid-1<n1)l1=nums1[mid-1];
            if(mid>=0 && mid<n1)r1=nums1[mid];
            if(mid2-1>=0 && mid2-1<n2)l2=nums2[mid2-1];
            if(mid2>=0 && mid2<n2)r2=nums2[mid2];

            if(l1<=r2 && l2<=r1){
                  if((n1+n2)%2==0)return (max(l1,l2)+min(r1,r2))/2;
         else{
            return min(r1,r2);
         }
            }
            else if(l1>r2)high=mid-1;
            else{
                low=mid+1;
            }
         }
       return 0;
    }
};