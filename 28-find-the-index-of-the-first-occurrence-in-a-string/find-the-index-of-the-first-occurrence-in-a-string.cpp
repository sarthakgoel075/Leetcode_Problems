class Solution {
public:
    int strStr(string haystack, string needle) {
        int ind=0;
        int n=haystack.length();
        int currind=0;
        int count=0;
        while(ind<n){
           
            if(haystack[ind]==needle[currind]){
                count++;
                ind++;
                currind++;
                 if(currind==needle.length()){
                return ind-needle.length();
            }
            }
            else{
                currind=0;
                ind=ind-count+1;
                count=0;
            }
        }
        return -1;
    }
};