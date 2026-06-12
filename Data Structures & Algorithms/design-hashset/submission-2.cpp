class MyHashSet {
private:
    struct Node{
        int k;
        Node* next;
        Node(int val): k(val), next(nullptr){}
    };
    vector<Node*> v{100000};
public:
    // MyHashSet(): v(1000001,false) {
    // }
    // void add(int key) {
    //     v[key]=true;
    // }
    // void remove(int key) {
    //     v[key]=false;
    // }
    // bool contains(int key) {
    //     return v[key];
    // }
    MyHashSet(){
        for(auto &bkt : v){
            bkt = new Node(0); //each bucket with a dummy head node
        }
    }
    void add(int key){
        Node* curr = v[key%10000];
        while(curr->next){
            if(curr->next->k == key) return;
        
            curr = curr->next;
        }
        curr->next = new Node(key);
    }
    void remove(int key){
        Node* curr = v[key%10000];
        while(curr->next){
            if(curr->next->k == key){
                // curr->next = curr->next->next;
                Node* temp = curr->next;
                curr->next= temp->next;
                delete temp;
                return;
            }
        
            curr = curr->next;
        }
    }
    bool contains(int key){
        Node* curr = v[key%10000];
        while(curr->next){
            if(curr->next->k == key) return true;
        
            curr = curr->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */