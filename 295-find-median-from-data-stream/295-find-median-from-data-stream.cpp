class MedianFinder {
    priority_queue<int,vector<int>,greater<int>>right;
    priority_queue<int>left;
    
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.size()==0){
            left.push(num);
            return ;
        }
        if(num<=left.top()){
            left.push(num);
        }
        else{
            right.push(num);
        }
        if(left.size()>right.size()+1){
            int val=left.top();
            left.pop();
            right.push(val);
        }
        else if(right.size()>left.size()){
            int val=right.top();
            right.pop();
            left.push(val);
        }
    }
    
    double findMedian() {
        if(left.size()==right.size()){
            return (left.top()+right.top())/2.0;
        }
        return left.top();
       
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */