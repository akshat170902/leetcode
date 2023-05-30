class MyHashSet {
    bitset< 1000001 > B;
public:
    
    void add(int key) {
        B[key] = true;
    }
    
    void remove(int key) {
        B[key] = false;
    }
    
    bool contains(int key) {
        return B[key];
    }
};