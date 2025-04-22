class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        long long shift=0;
        while(left!=right){
           left =left>>1;
           right= right>>1;
            shift=shift+1;
        }
        return left<<shift;
    }
};