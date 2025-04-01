class Solution {
public:
    int myAtoi(string s) {
       s.erase(0,s.find_first_not_of(' '));
       long long a=0;
       int sign=1;
       if(s[0]=='-')sign=-1;
       else if(s[0]=='+'){
        sign=1;
       }
       else if(s[0]-'0'>=0 && s[0]-'0'<=9){
    a=s[0]-'0';
       }
       else return 0;
       int n=s.size();
       for(int i=1;i<n;i++){
     
        if(s[i]-'0'>=0 && s[i]-'0'<=9){
               if((a*10+s[i]-'0')>=INT_MAX){
            if(sign==1)return INT_MAX;
            else if(sign==-1 && (a*10+s[i]-'0')==INT_MAX){
                return -1*INT_MAX;
            }
            else{
                return INT_MIN;
            }
        }
            a=a*10+s[i]-'0';
        }
        else break;
       }
       return sign*a;
    }
};