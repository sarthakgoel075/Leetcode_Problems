class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i=0;
        while(n>0){
            if(i>=flowerbed.size())return false;
           if(flowerbed[i]==0){
            if(((i-1>=0 && flowerbed[i-1]==0)|| i-1<0) && ((i+1<flowerbed.size() && flowerbed[i+1]==0)||i+1>=flowerbed.size())){
                flowerbed[i]=1;
                n--;
                i++;
            }
           }
           i++;
               }
        return true;
    }
};