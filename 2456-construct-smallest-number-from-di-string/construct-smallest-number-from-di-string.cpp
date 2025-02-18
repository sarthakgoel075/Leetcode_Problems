class Solution {
public:
    string smallestNumber(string pattern) {
       int n=pattern.size();
       vector<int>num(n,0);
       int curr=0;
       for(int i=n-1;i>=0;i--){
        if(pattern[i]=='D'){
            curr++;
            num[i]=curr;
        }
        else{
            num[i]=curr;
            curr=0;
        }
       }
       string ans="";
       int maxi=0;
       int pre=0;
       if(pattern[0]=='I'){
            pre+=1;
            ans+=to_string(pre);
       }
       else{
        pre=num[0]+1;
       ans+=to_string(pre);

       }
       maxi=pre;
       for(int i=0;i<n;i++){
        if(pattern[i]=='I'){
            pre=maxi+1+num[i];
            maxi=max(maxi,pre);
            ans+=to_string(pre);

        }
        else{
            pre--;
          ans+=to_string(pre);
        }
       }
       return ans;
    }
};