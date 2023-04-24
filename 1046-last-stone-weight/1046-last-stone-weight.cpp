class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int >pq;
        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }
        while(pq.size()>=2){
            int m1=pq.top();
            pq.pop();
            int m2=pq.top();
            pq.pop();
            if(m1!=m2){
                pq.push(m1-m2);
            }
        }
        if(pq.size()==1)
        return pq.top();
        return 0;
    }
};