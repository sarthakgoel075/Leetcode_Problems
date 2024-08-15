class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int curr10=0;
        int curr5=0;
        for(auto i:bills){
            if(i==5){
                curr5++;
            }
            else if(i==10){
                 if(curr5>=1){
                    curr5--;
                    curr10++;
                 }
                 else{
                    return false;
                 }
            }
            else{
                if(curr5>=1 && curr10>=1){
                    curr5--;
                    curr10--;
                    
                }
               else if(curr5>=3){
                curr5=curr5-3;
               }
               else{
                return false;
               }
            }
        }
        return true;
    }
};