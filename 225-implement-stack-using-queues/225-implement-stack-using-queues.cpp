class MyStack {
    queue<int>p,q;
    bool flag=true;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        if(flag){
            p.push(x);
            while(q.empty()==false){
                int j=q.front();
                q.pop();
                p.push(j);
                
            }
            flag=false;
        }
        else{
            q.push(x);
            while(p.empty()==false){
                int j=p.front();
                p.pop();
                q.push(j);
            }
            flag=true;
        }
    }
    
    int pop() {
        if(flag){
            int j=q.front();
             q.pop();
           return j;
        }
        else{
            int j=p.front();
             p.pop();
           return j;
        }
    }
    
    int top() {
        if(flag){
            int j=q.front();
             
           return j;
        }
        else{
            int j=p.front();
            
           return j;
        }
    }
    
    
    bool empty() {
        if(flag){
           
           return q.empty();
        }
        else{
            
           return p.empty();
        }
    
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