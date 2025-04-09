class Solution {
public:
    bool check(int n){
        if(n==1)return true;
        else if(n%2==1){
            return false;
        }
        return check(n/2);
    }
    bool isPowerOfTwo(int n) {
        if(n<=0)return false;
        return check(n);
    }
};