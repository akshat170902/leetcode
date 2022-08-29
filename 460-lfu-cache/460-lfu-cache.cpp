
struct Node{
    
    int key,value,cnt;
    Node*next;
    Node*prev;
    Node(int key,int value){
        this->key=key;
        this->value=value;
        cnt=1;
    }
};
struct Dll{
    
    int size;
    Node*head;
    Node*tail;
    Dll(){
        head=new Node(0,0);
        tail=new Node(0,0);
        head->next=tail;
        tail->prev=head;
        size=0;
    }
    void addFront(Node*node){
        Node*temp=head->next;
        head->next=node;
        node->prev=head;
        node->next=temp;
        temp->prev=node;
        size++;
    }
    void addBack(Node*node){
        Node*temp=tail->prev;
        temp->next=node;
        node->prev=temp;
        node->next=tail;
        tail->prev=node;
        size++;
    }
    
    void deleteNode(Node*node){
        Node*tempNext=node->next;
        Node*tempPrev=node->prev;
        tempNext->prev=tempPrev;
        tempPrev->next=tempNext;
        
        size--;
    }
};
class LFUCache{
    unordered_map<int,Dll*>freqList;
    unordered_map<int,Node*>keyNode;
    int curcap;
    int cap;
    int freq;
public:
    LFUCache(int capacity) {
        cap=capacity;
        curcap=0;
        freq=0;
    }
    
    void updateList(Node*node){
        keyNode.erase(node->key);
        freqList[node->cnt]->deleteNode(node);
        if(freqList[node->cnt]->size==0){
            if(node->cnt==freq){
                freq++;
            }
        }
        Dll*newList=new Dll();
        if(freqList.count(node->cnt+1)!=0){
           newList=freqList[node->cnt+1];
        }
        node->cnt++;
        newList->addFront(node);
        freqList[node->cnt]=newList;
        keyNode[node->key]=node;
    }
    int get(int key) {
        if(keyNode.count(key)==0){
            return -1;
        }
        else{
            Node*node=keyNode[key];
            int val=node->value;
            updateList(node);
            return val;
        }
    }
    
    void put(int key, int value) {
        if(cap==0)
            return;
        if(keyNode.count(key)==0){
            if(curcap==cap){
                Dll*list=freqList[freq];
                Node*node=list->tail->prev;
                keyNode.erase(node->key);
                list->deleteNode(list->tail->prev);
                curcap--;
            }
            curcap++;
            freq=1;
            Dll*newList=new Dll();
            if(freqList.count(freq)!=0){
                newList=freqList[freq];
            }
            Node*node=new Node(key,value);
            newList->addFront(node);
            freqList[freq]=newList;
            keyNode[key]=node;
        }
        else{
            Node*node=keyNode[key];
            node->value=value;
            updateList(node);

        }
    }
};