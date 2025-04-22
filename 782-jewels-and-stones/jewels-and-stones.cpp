class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int>mp;
        for(auto i:jewels){
            mp[i]++;
        }
        int count=0;
        for(auto i:stones){
            if(mp.count(i)){
                count++;
            }
        }
        return count;
    }
};