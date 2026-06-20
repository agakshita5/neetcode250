class MyHashMap {
private:
    struct Node{
        vector<int> vec;
        Node* next;
        Node(vector<int> v): vec(v), next(nullptr){}
    };
    vector<Node*> outerV{10000};
public:
    MyHashMap() {
        for(auto &bkt: outerV){
            bkt = new Node({0,0}); // each bkt has a dummy head node
        }
    }
    /*
    void put(int key, int value) {
        for(int i=0;i<v.size();i++){
            if(v[i][0]==key){
                v[i][1]=value;
                return;
            }
        }
        v.push_back({key,value});
    }
    
    int get(int key) {
        for(int i=0;i<v.size();i++){
            if(v[i][0]==key){
                return v[i][1];
            }
        }
        return -1;
    }
    
    void remove(int key) {
        for(int i=0;i<v.size();i++){
            if(v[i][0]==key){
                v.erase(v.begin()+i);
            }
        }
    }
    */

    void put(int key, int value){
        Node* curr = outerV[key%10000];
        while(curr->next){
            if(curr->next->vec[0] == key ) {
                curr->next->vec[1] = value;
                return;
            }
            curr = curr->next;
        }
        curr->next = new Node({key,value});
    }
    void remove(int key){
        Node* curr = outerV[key%10000];
        while(curr->next){
            if(curr->next->vec[0] == key ){
                Node* temp = curr->next;
                curr->next = temp->next;
                delete temp;
                return;
            }
            curr = curr->next;
        }
    }
    int get(int key){
        Node* curr = outerV[key%10000];
        while(curr->next){
            if(curr->next->vec[0] == key ) return curr->next->vec[1];
            curr = curr->next;
        }
        return -1;
    }
    
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */