class Solution {
public:
    int actualnumber;
    bool fun(string num,int i,int curr){
        if(i==num.size()){
            if(curr==actualnumber)return true;
            return false;
        }
        int t=0;
       for(int j=i;j<num.size();j++){
           t=t*10+(num[j]-'0');
            if (curr + t > actualnumber) break; 
          if(fun(num,j+1,(curr+t)))return true;
       }
       return false;
    }
    int punishmentNumber(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            int sq=i*i;
            actualnumber=i;
            if(fun(to_string(sq),0,0)){
                cout<<sq<<"     ";
                ans+=sq;
            }
        }
        return ans;
    }
};