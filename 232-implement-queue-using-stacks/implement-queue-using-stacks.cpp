class MyQueue {
public:
    stack<int>st;
    MyQueue() {
    }
    
    void push(int x) {
       st.push(x);
    }
    
    int pop() {
        stack<int>dummy;
        int size=st.size();
        for(int i=0;i<size-1;i++){
            int t=st.top();
            st.pop();
            dummy.push(t);
        }
        int t=st.top();
        st.pop();
        while(!dummy.empty()){
            int t=dummy.top();
            dummy.pop();
            st.push(t);
        }
        return t;
    }
    
    int peek() {
        stack<int>dummy;
        int size=st.size();
        for(int i=0;i<size;i++){
            int t=st.top();
            st.pop();
            dummy.push(t);
        }
        int t=dummy.top();
        while(!dummy.empty()){
             int t=dummy.top();
            dummy.pop();
            st.push(t);
        }
        return t;
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */