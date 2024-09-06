class Solution {
public:
    bool wordPattern(string pattern, string s) {
        s=s+' ';
        unordered_map<string,char>mp1;
        unordered_map<char,string>mp2;
        string temp="";
        int ind=0;
        for(auto i:s){
            if(i==' '){
               if(mp1.count(temp)>0 && mp1[temp]!=pattern[ind]){
                return false;
               }
               else{
                mp1[temp]=pattern[ind];
               }

                if(mp2.count(pattern[ind])>0 && mp2[pattern[ind]]!=temp){
                return false;
               }
               else{
                mp2[pattern[ind]]=temp;
               }
               ind++;
               temp.clear();
            }
            else{
            temp+=i;
            }

        }
      
        return ind == pattern.size(); 
    }
};