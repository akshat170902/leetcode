class MinStack {
    vector<int>stack;
        int nim=INT_MAX;
public:
    MinStack() {
         
        
    }
    
    void push(int val) {
        stack.push_back(val);
        
        nim=min(nim,val);
    }
    
    void pop() {
        stack.pop_back();
        nim=INT_MAX;
        for(int i:stack)nim=min(nim,i);
        
    }
    
    int top() {
        return stack[stack.size()-1];
    }
    
    int getMin() {
        return nim;
            
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */