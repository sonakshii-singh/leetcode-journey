class MinStack {
public:
    stack<long long> st;
    long long mini=INT_MAX;
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()){
            st.push(value);
            mini=value;
        }
        else if(value>mini) st.push(value);
        else {
            st.push(2LL*value-mini);
            mini=value;
        }
    }
    
    void pop() {
        if(st.empty()) return;
        if(st.top()<mini)
          mini=2LL*mini - st.top();
        st.pop();  
    }
    
    int top() {
        if(st.top()>mini) return st.top();
        return mini;
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */