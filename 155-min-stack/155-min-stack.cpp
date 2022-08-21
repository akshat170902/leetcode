class MinStack {
    stack<long long>stack;
    long long nim=INT_MAX;
public:
    MinStack() {
         
        
    }
    
    void push(int val) {
        if(val<nim){
            stack.push((long)2*val-nim);
            nim=val;
            return ;
        }
        stack.push(val);
        
    }
    
    void pop() {
        if(stack.top()<nim){
            nim=2*nim-stack.top();
        }
        stack.pop();
        
    }
    
    int top() {
        if(stack.top()<nim){
            return nim;
        }
        return stack.top();
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