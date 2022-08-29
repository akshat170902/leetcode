class BrowserHistory {
    int idx;
    int size;
    vector<string>site;
public:
    BrowserHistory(string homepage) {
        idx=0;
        size=0;
        site.push_back(homepage);
    }
    
    void visit(string url) {
        if(size<=idx){
            if(site.size()==size+1){
                site.push_back(url);
                
            }
            else{
                site[size+1]=url;
            }
            idx++;
            size++;
        }
        else{
            site[idx+1]=url;
            size=idx+1;
            idx++;
        }
    }
    
    string back(int steps) {
        idx=max(0,idx-steps);
        return site[idx];
    }
    
    string forward(int steps) {
        idx=min(size,idx+steps);
        return site[idx];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */