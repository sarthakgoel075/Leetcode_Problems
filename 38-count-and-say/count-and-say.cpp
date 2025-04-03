class Solution {
public:
    string fun(string a){
        string ans="";
        int count=0;
        int n=a.size();
        char pre=a[0];
        for(int i=0;i<n;i++){
          if(i==0)count=1;
          else{
            if(a[i]==pre)count++;
            else{
                ans+=to_string(count);
                ans+=pre;
                count=1;
                pre=a[i];
            }
          }
        }
         ans+=to_string(count);
                ans+=pre;
                return ans;
    }
    string countAndSay(int n) {
        string ans="1";
            while(n>1){
            ans=fun(ans);
            n--;
        }
        return ans;
    }
};