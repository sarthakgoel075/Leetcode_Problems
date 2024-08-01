class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count=0;
        for(auto i:details){
            int num=(i[11]-'0')*10+(i[12]-'0');
            if(num>60)count++;
        }
        return count;
    }
};