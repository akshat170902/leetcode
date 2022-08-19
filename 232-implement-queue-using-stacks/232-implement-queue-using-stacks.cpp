class MyQueue {
    stack<int>s1,s2;
    
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s2.size()==0){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int val=s2.top();
        s2.pop();
        return val;
    }
    
    int peek() {
        if(s2.size()==0){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int val=s2.top();
        
        return val;
    }
    
    bool empty() {
        return s1.empty()?s2.empty()?true:false:false;
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