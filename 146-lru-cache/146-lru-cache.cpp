class LRUCache {
    int cap=0;
    list<pair<int,int>>ll;
    unordered_map<int,list<pair<int,int>>::iterator>m;
public:
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        auto it=m.find(key);
        if(it==m.end())
            return -1;
        int val=m[key]->second;
        if(m[key]!=ll.end())
        ll.erase(m[key]);
        ll.push_front({key,val});
        m[key]=ll.begin();
        return val;
    }
    
    void put(int key, int value) {
        auto it=m.find(key);
        if(it==m.end()){
            if(ll.size()==cap){
                pair<int,int>p=ll.back();
                ll.pop_back();
                m.erase(p.first);
            }
            ll.push_front({key,value});
            m[key]=ll.begin();
        }
        if(m[key]!=ll.end())
        ll.erase(m[key]);
        ll.push_front({key,value});
        m[key]=ll.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */