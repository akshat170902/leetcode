class RandomizedSet {
    unordered_map<int,int>m;
    
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(m.count(val)>0){
            return false;
        }
        m[val]=m.size();
        return true;
    }
    
    bool remove(int val) {
        if(m.count(val)>0){
            m.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int val=rand()%m.size();
        int ans=0;
        auto it=m.begin();
        for(int i=0;i<=val;i++){
            ans=it->first;
            it++;
        }
        return ans;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */