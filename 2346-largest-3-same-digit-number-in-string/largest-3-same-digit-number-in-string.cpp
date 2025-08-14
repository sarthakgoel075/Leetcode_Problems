class Solution {
public:
    string largestGoodInteger(string num) {
        int twodigit=0;
        int maxi=INT_MIN;
        char pre=num[0];
        for(int i=1;i<num.size();i++){
          if(num[i]==pre){
            if(twodigit){
               twodigit=0;
               maxi=max(maxi,num[i]-'0');
          }
          else{
            twodigit=1;
          }
        }
        else{
            twodigit=0;
        }
        pre=num[i];
    }
    string ans="";
    if(maxi==INT_MIN)return ans;
    for(int i=0;i<3;i++){
        ans+=to_string(maxi);
    }
    return ans;
    }
};