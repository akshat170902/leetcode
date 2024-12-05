class Solution {
public:
    
    bool canChange(string start, string target) {
        int n=start.size();
        queue<pair<int,int>>startQ,targetQ;
        for(int i=0;i<n;i++){
            if(start[i]!='_'){
                startQ.push({i,start[i]});
            }
            if(target[i]!='_'){
                targetQ.push({i,target[i]});
            }
        }
        if(startQ.size()!=targetQ.size()){
            return false;
        }
        
        while(startQ.size()){
            auto [sIdx,sChar]=startQ.front();startQ.pop();
            auto [tIdx,tChar]=targetQ.front();targetQ.pop();
            
            if(sChar!=tChar){
                return false;
            }
            
            if(sChar=='L'&&sIdx<tIdx){
                return false;
            }
            
            if(sChar=='R'&&sIdx>tIdx){
                return false;
            }
        }
        return true;
    }
};