class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int t=1;
        while(true){
 long long curr = (long long)num1 - 1LL * t * num2;
            if(curr<0)return -1;
            int min_bit=__builtin_popcountll(curr);
            if(min_bit<=t && t<=curr){
                return t;
            }
            t++;
        }
        return t;
    }
};