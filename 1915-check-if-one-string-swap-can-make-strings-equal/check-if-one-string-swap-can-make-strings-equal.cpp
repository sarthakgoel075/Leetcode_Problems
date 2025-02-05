class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        char ch1;
        char ch2;
        int count=0;
        if(s1.size()!=s2.size())return false;
        int n=s1.size();
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                if(count==0){
                    count++;
                    ch1=s1[i];
                    ch2=s2[i];
                }
                else if(count==1){
                    if(ch1!=s2[i] ||ch2!=s1[i]){
                        return false;
                    }
                    count++;
                }
                else if(count>1){
                    return false;
                }
            }
        }
        if(count==1){
            return false;
        }
        return true;
    }
};