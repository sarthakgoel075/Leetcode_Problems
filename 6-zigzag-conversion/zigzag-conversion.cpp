class Solution {
public:
    string convert(string s, int n) {
        string a="";
        if(n==1)
        return s;
        for(int i=0;i<n;i++){
            int inc=(2*(n-1));
            for(int j=i;j<s.size();j+=inc){
                a+=s[j];
                if(i>0 && i<n-1){
                    if(j+inc-2*i<s.size()){
                    a+=s[j+inc-(2*i)];}
                }
                
                   
                
            }
        }
        return a;
    }
};