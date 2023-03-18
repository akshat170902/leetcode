class BrowserHistory {
    vector<string>list;
    int idx=-1;
    int maxSize=0;
    
public:
    BrowserHistory(string homepage) {
        list.push_back(homepage);
        idx=0;
        maxSize=1;
    }
    
    void visit(string url) {
        if(list.size()-1>idx){
            list[idx+1]=url;
            idx++;
            maxSize=idx+1;
        }
        else{
            list.push_back(url);
            idx++;
            maxSize++;
        }
    }
    
    string back(int steps) {
        int val=min(steps,idx);
        idx-=val;
        return list[idx];
    }
    
    string forward(int steps) {
        int val=min(steps,maxSize-idx-1);
        idx+=val;
        return list[idx];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */