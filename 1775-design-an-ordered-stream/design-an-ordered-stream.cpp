class OrderedStream {
public:
   
     int ptr;
    vector<int> v;
    vector<string> store;

    OrderedStream(int n) {
        ptr = 1;
        v = vector<int>(n+1, 0);         // Declare and initialize member variables
        store = vector<string>(n+2);     // Declare and initialize member variables
    }
   

    vector<string> insert(int idKey, string value) {
        v[idKey]=1;
        store[idKey]=value;
         vector<string>ans;
        if(idKey==ptr ){
           
            int i=idKey;
            while(i<v.size() && v[i]==1 ){
                ans.push_back(store[i]);
                i++;
            }
            ptr=i;
        }
        
        return ans;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */