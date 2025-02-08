class NumberContainers {
public:
    unordered_map<int,set<int>>idx;//number is at index
    unordered_map<int,int>num;// at this index what is number
    NumberContainers() {}
        
    
    void change(int index, int number) {
           if(num.count(index)){
            idx[num[index]].erase(index);
           }
           num[index]=number;
           idx[number].insert(index);
    }
    
    int find(int number) {
        if(!idx[number].empty()){
            return *idx[number].begin();
        }
        else return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */