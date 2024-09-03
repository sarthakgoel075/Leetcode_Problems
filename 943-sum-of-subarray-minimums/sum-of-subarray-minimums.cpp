class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int mod=1000000007;
        vector<int>presmall(n);
        vector<int>nextsmall(n);
        stack<int>pre;
        stack<int>next;
        //find the previous small for all elemnt.........................
        for(int i=0;i<n;i++){
        while(!pre.empty() && arr[pre.top()]>arr[i]){
             pre.pop();
        }
        if(pre.empty()){
            presmall[i]=-1;
            pre.push(i);
        }
        else{
            presmall[i]=pre.top();
            pre.push(i);
        }
        }
        //find the next smallest index for all ..............
        for(int i=n-1;i>=0;i--){
        while(!next.empty() && arr[next.top()]>=arr[i]){
             next.pop();
        }
        if(next.empty()){
            nextsmall[i]=n;
            next.push(i);
        }
        else{
            nextsmall[i]=next.top();
            next.push(i);
        }
        }
       
       long long ans=0;
       for(int i=0;i<n;i++){
        long long curr=(i-presmall[i])*(nextsmall[i]-i);
        curr*=arr[i];
        ans+=curr;
        ans=ans%mod;
       }
        return int(ans);
    }
};