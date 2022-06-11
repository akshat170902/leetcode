class MyQueue {stack<int>s,srev;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s.push(x);
    }
    
    int pop() {
        while(!s.empty()){
            int x=s.top();
            srev.push(x);
            s.pop();
        }
        int ans=srev.top();
        srev.pop();
        while(!srev.empty()){
         int x=srev.top();
            s.push(x);
            srev.pop();   
        }
        return ans;
    }
    
    int peek() {
         while(!s.empty()){
            int x=s.top();
            srev.push(x);
            s.pop();
             
        }
         int ans=srev.top();
      
        while(!srev.empty()){
         int x=srev.top();
            s.push(x);
            srev.pop();   
        }
        return ans;
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