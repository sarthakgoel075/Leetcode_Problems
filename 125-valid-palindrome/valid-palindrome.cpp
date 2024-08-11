class Solution {
public:
    bool check(string temp){
        int n=temp.size();
        for(int i=0;i<n/2;i++){
            if(temp[i]!=temp[n-i-1]){
                return false;
            }
        }
        return true;
    }
    bool isPalindrome(string s) {
        string temp="";
        for(auto i:s){
            if((i>='a' && i<='z')|| (i>='A' && i<='Z') || (i>='0' && i<='9')){
                if((i>='a' && i<='z') || (i>='0' && i<='9') ){
                    temp+=i;
                }
                else{
                     char c=char(tolower(i));
                     temp+=c;
                }
            }
        }
        return check(temp);
    }
};