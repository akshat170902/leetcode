class MyQueue {
    stack<int>s;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        if(s.empty()){
            s.push(x);
            return ;
        }
        int val=s.top();
        s.pop();
        push(x);
        s.push(val);
    }
    
    int pop() {
        int val=s.top();
        s.pop();
        return val;
    }
    
    int peek() {
        return s.top();
    }
    
    bool empty() {
        return s.empty();
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