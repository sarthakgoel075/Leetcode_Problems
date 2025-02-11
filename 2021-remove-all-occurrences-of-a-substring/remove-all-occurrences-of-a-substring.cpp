class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(true){
            int ind=s.find(part);
            if(ind==string::npos){
                break;
            }
            s.erase(ind,part.size());
        }
        return s;
    }
};