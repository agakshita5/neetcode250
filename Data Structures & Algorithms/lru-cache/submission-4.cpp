struct Node{
    pair<int,int> data;
    Node* next;
    Node* prev;
    Node(pair<int,int> v): data(v), prev(nullptr), next(nullptr){}
};

class LRUCache {
    Node* tail;
    Node* head;
    unordered_map<int, Node*> mp;
    int sz;

public:
    LRUCache(int capacity) {
        sz = capacity;
        head = new Node({-1,-1});
        tail = new Node({-1,-1});
        head->next = tail;
        tail->prev = head;
    }
    void appendNode(Node* n){
        n->prev = tail->prev;
        tail->prev->next = n;
        tail->prev = n;
        n->next = tail;
    }
    void moveToEnd(Node* n){
        // detach from its position
        n->prev->next = n->next;
        n->next->prev = n->prev;

        // move to end
        appendNode(n);
    }

    int get(int key) {
        if(!mp.empty() && mp.find(key) != mp.end()){
            Node* fetched = mp[key]; // {k,v}

            if(fetched == tail->prev) return fetched->data.second;

            moveToEnd(fetched);

            return fetched->data.second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        // if key in mp -> node also exists...update node value
        if(mp.find(key) != mp.end()){
            // update node's data.second
            Node* n = mp[key];
            n->data.second = value; 

            moveToEnd(n);
        }

        // if key not in mp -> create node [curr = new node({key,value})]
        else{
            Node* curr = new Node({key, value});

            // if mp.size >= sz....remove lru
            if(mp.size() >= sz){
                // lru deleted from mp
                int k = head->next->data.first;
                mp.erase(k);

                // lru deleted from dll
                Node* toDel = head->next;
                toDel->next->prev = head;
                head->next = toDel->next;
                delete toDel; 
            }

            appendNode(curr);

            // save in mp
            mp[key] = curr;
        }
        return;
    }
};
