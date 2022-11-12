class MedianFinder {
    priority_queue<int,vector<int>,greater<int>>minH;
    priority_queue<int>maxH;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxH.size()==0||num<maxH.top()){
            maxH.push(num);
        }
        else{
            minH.push(num);
        }
        if(maxH.size()>minH.size()+1){
            int val=maxH.top();
            maxH.pop();
            minH.push(val);
        }
        else if(maxH.size()<minH.size()){
            int val=minH.top();
            minH.pop();
            maxH.push(val);
        }
    }
    
    double findMedian() {
        if(maxH.size()==minH.size()){
            return (maxH.top()+minH.top())/2.0;
        }
        return maxH.top();
        // return 0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */