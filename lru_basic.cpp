struct node{
    int val, key;
    node *prev;
    node *next;
};

map<int, node *> LRUCacheMap;

void LRUSetCacheMap(int key, struct node *value){
    // cout<<"adding to cache \n"<< "key: "<<value->key<<" value:"<< value->val<<"keyey: "<< key<<endl;
    LRUCacheMap[key] = value;
}

void LRURemoveCacheMap(int key){
    LRUCacheMap.erase(key);
}

class list{
    private: node *head, *tail;
    private: int curr_size;
    private: int limit;
    public: list(){
        head = NULL;
        tail = NULL;
        curr_size = 0;
    };
    node* addItem(int value, int key){
        node *temp = LRUCacheMap[key];
        node *destroy;
        if(temp!=NULL){
            temp->val = value;
            node *temp_temp = temp;
            if(temp_temp->prev!=NULL){
                if(temp_temp->next != NULL){
                    temp_temp->prev->next = temp_temp->next;
                }else{
                    temp_temp->prev->next = NULL;
                }    
            }else{
                if(temp_temp->next != NULL){
                    tail = temp_temp->next;
                    temp_temp->next->next = temp;
                    temp->prev = temp->next;
                }
            }
            
        }else{
            temp = new node();
            temp->prev = NULL;
            temp->next = NULL;
            temp->val = value;
            temp->key = key;
            LRUSetCacheMap(key, temp);  
            curr_size++;
        } 
        temp->next = NULL;
        temp->prev = head;
        if(head!=NULL){
            head->next = temp;
        }
        head = temp;
        if(tail==NULL){
            tail = head;
        }
        if(curr_size>limit){
            int key_to_rm = tail->key;
            LRURemoveCacheMap(key_to_rm);
            tail = tail->next;
            curr_size--;
        }
        return temp;
    };
  
    void setCapacity(int capacity){
        limit = capacity;
    };
    
    public: ~list(){
        while(tail!=NULL){
            node * drop = tail;
            tail = tail->next;
            delete[] drop;
        }
    }
};

list cache_list;

LRUCache::LRUCache(int capacity) {
        LRUCacheMap.clear();
        // cache_list.clear_list();
        // list *cache_list2 = &cache_list;
        // list cache_list;
    cache_list.setCapacity(capacity);    
}

int LRUCache::get(int key) {
    node *page =  LRUCacheMap[key];
    if(page!=NULL){
        int val = page->val;
            cache_list.addItem(val, key);
            return val;
    }else{
        return -1;
    }
}
void LRUCache::set(int key, int value) {
    node *page = cache_list.addItem(value, key);
    // LRUSetCacheMap(key, page);
}


