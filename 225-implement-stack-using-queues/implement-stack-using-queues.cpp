class MyStack {
public:
    MyStack() {
    }
     queue<int>q1;

    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int size=q1.size();
        int t=0;
        for(int i=0;i<size-1;i++){
             t=q1.front();
            q1.pop();
            q1.push(t);
    }
       t=q1.front();
      q1.pop();
      return t;
    }
    
    int top() {
         int size=q1.size();
         int t=0;
        for(int i=0;i<size;i++){
            t=q1.front();
            q1.pop();
            q1.push(t);
    }
    return t;
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */