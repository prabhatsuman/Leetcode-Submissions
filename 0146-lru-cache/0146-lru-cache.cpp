class LRUCache
{
    public:
        class node
        {
            public:
                int key;
            int val;
            node * next;
            node * prev;
            node(int key, int val)
            {
                this->key = key;
                this->val = val;
            }
        };
    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);
    int cap;

    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    unordered_map<int, node*> m;
    void addnode(node *newnode)
    {
        node *temp = head->next;
        head->next = newnode;
        newnode->prev = head;
        newnode->next = temp;
        temp->prev = newnode;
    }
    void deletenode(node* delnode)
    {
        node*pre=delnode->prev;
        node*next=delnode->next;
        pre->next=next;
        next->prev=pre;
    }

    int get(int key) {
        if(m.find(key)!=m.end())
        {
            node*res=m[key];
            int ans=res->val;
            m.erase(key);
            deletenode(res);
            addnode(res);
            m[key]=head->next;
            return ans;
        }
        return -1;
    }

    void put(int key, int value) {
        if(m.find(key)!=m.end())
        {
            node* res=m[key];
            m.erase(key);
            deletenode(res);
        }
        if(m.size()==cap)
        {
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key,value));
        m[key]=head->next;
    }
};

/**
 *Your LRUCache object will be instantiated and called as such:
 *LRUCache* obj = new LRUCache(capacity);
 *int param_1 = obj->get(key);
 *obj->put(key,value);
 */