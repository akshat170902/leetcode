
class Node{
    public:
    string key;
    int freq;
    Node*next,*prev;
    Node(string key){
        this->key=key;
        freq=1;
    }
};
class DLL{
    public:
    int size;
    Node*head;
    Node*tail;
    DLL(){
        head=new Node("");
        tail=new Node("");
        head->next=tail;
        tail->prev=head;
        size=0;
    }
    void addFront(Node*node){
        Node*temp=head->next;

        head->next=node;
        temp->prev=node;

        node->next=temp;
        node->prev=head;
        size++;
    }
    void deleteNode(Node*node){
        Node*front=node->next;
        Node*back=node->prev;

        front->prev=back;
        back->next=front;
        size--;
    }
};
class AllOne {
    map<int,DLL*>freqList;
    unordered_map<string,Node*>keyNode;
    int minimum,maximum;
public:
    AllOne() {
        minimum=0;
        maximum=0;
    }
    
    void inc(string key) {
        
            Node*newNode=new Node(key);

            if(keyNode.count(key)!=0){
                newNode=keyNode[key];
                freqList[newNode->freq]->deleteNode(newNode);
                if(freqList[newNode->freq]->size==0){
                    freqList.erase(newNode->freq);
                }   
                newNode->freq++;
            }
            
            DLL*newList=new DLL();
            if(freqList.count(newNode->freq)!=0){
                newList=freqList[newNode->freq];
            }
            newList->addFront(newNode);
            freqList[newNode->freq]=newList;
            keyNode[newNode->key]=newNode;
        
    }
    
    void dec(string key) {
        
        Node*newNode=keyNode[key];
        keyNode.erase(key);
        freqList[newNode->freq]->deleteNode(newNode);
        if(freqList[newNode->freq]->size==0){
            freqList.erase(newNode->freq);
        }

        newNode->freq--;
        if(newNode->freq!=0){
            keyNode[key]=newNode;
            DLL*newList=new DLL();
            if(freqList.count(newNode->freq)!=0){
                newList=freqList[newNode->freq];
            }
            newList->addFront(newNode);
            freqList[newNode->freq]=newList;
        }
    }
    
    string getMaxKey() {
        if(freqList.size()==0){
            return "";
        }
        auto it=--freqList.end();
        return it->second->tail->prev->key;
    }
    
    string getMinKey() {
        // cout<<freqList.size()<<endl;
        if(freqList.size()==0){
            return "";
        }
        auto i=freqList.begin();
        return i->second->tail->prev->key;
    }
};
