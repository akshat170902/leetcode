class KthLargest {
    priority_queue<int,vector<int>,greater<int>>pq;
    int cap=0;
public:
    int valueAdder(int val){
            if(pq.size()<cap){
                pq.push(val);
            }
            else{
                if(pq.top()<val){
                    pq.pop();
                    pq.push(val);
                }
            }
        return pq.top();
    }
    KthLargest(int k, vector<int>& nums) {
        cap=k;
        for(int i=0;i<nums.size();i++){
            valueAdder(nums[i]);
            
        }
    }
    
    int add(int val) {
        return valueAdder(val);
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */