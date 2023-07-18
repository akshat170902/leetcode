class LRUCache {
    unordered_map<int,pair<int,list<int>::iterator>>m;
    list<int>list;
    int cap=0;
public:
    LRUCache(int capacity) {
        cap=capacity;
    }
    void updateList(int key,int val){
        auto it=m[key].second;
        if(it!=list.end()){
            list.erase(it);
        }
        list.push_front(key);
        m[key].first=val;
        m[key].second=list.begin();
    }
    int get(int key) {
        if(m.count(key)==0){
            return -1;
        }
        updateList(key,m[key].first);
        return m[key].first;
    }
    
    void put(int key, int value) {
        if(m.count(key)==0){
            list.push_front(key);
            m[key].second=list.begin();
            m[key].first=value;
            if(list.size()>cap){
                int temp=list.back();
                list.pop_back();
                m.erase(temp);
            }
            return ;
        }
        updateList(key,value);
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */