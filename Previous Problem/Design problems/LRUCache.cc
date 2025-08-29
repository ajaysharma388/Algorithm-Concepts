#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key, value;
    Node* prev; 
    Node* next;
    Node(int _key, int _value)
    {
        this->key = _key;
        this->value = _value;
        this->next = nullptr;
        this->prev = nullptr;
    }
};   

class Cache
{
    Node* head;
    Node* tail;
    unordered_map<int, Node*> cache;
public:
    Cache() { 
        this->head = nullptr;
        this->tail = nullptr;
        this->cache.clear();
    }

    int getFromCache(int _key)
    {
        if(cache.find(_key) == cache.end())
            return -1;
        // the key is available.
        if(cache[_key] == head)
        {
            // cout << "At Head\n";
            // no movement is required.
            return cache[_key]->value;
        }
        if(tail->key == _key)
        {
            // if the node is at the end we need to move this to the head.
            tail = cache[_key]->prev;
            tail->next = nullptr;
            cache[_key]->prev = nullptr;
            cache[_key]->next = head;
            head->prev = cache[_key];
            head = cache[_key];
            // print();
        }
        else // this is the middle node.
        {
            cache[_key]->prev->next = cache[_key]->next;
            cache[_key]->next->prev = cache[_key]->prev;
            // now pluck the node.
            cache[_key]->prev = nullptr;
            cache[_key]->next = head;
            head->prev = cache[_key];
            head = cache[_key];
        }
        return head->value;
    }

    void updateTheKey(int _key, int _value)
    {
        cout << "Updating key " << _key << endl;
        int prevVal = getFromCache(_key);
        // print();
        head->value = _value;
    }

    void insertIntoCache(int _key, int _value)
    {
        cache[_key] = new Node(_key, _value);
        // now insert into head.
        // cout << "Key Created\n";
        if(head == nullptr && tail == nullptr)
        {
            tail = cache[_key];
            head = cache[_key];
        }
        else
        {
            head->prev = cache[_key]; 
            cache[_key]->next = head;
            head = cache[_key];    
        }
        // print();
    }

    void removeExpiredEntry()
    {
        int expiredKey = tail->key;
        if(tail == head)
        {
            tail = nullptr;
            head = nullptr;
        }
        else if(tail != head)
        {
            tail->prev->next = nullptr;
            tail = tail->prev;
        }
        delete cache[expiredKey];
        cache.erase(expiredKey);
    }

    void print()
    {
        Node* ptr = head;
        // cout << "\nHead: " << head->key << ": " << head->value << endl;
        cout << "Front: ";
        while(ptr)
        {
            cout << "[" << ptr->key << ": " << ptr->value << "] ";
            ptr = ptr->next;
        }
        cout << "\nReverse: ";
        ptr = tail;
        while(ptr)
        {
            cout << "[" << ptr->key << ": " << ptr->value << "] ";
            ptr = ptr->prev;
        }
        cout << "\n";
    }
};

class LRUCache 
{
    int capacity;
    int curSize;
    Cache *lruCache;
public:
    LRUCache(int _capacity) 
    {
        this->capacity = _capacity;
        this->curSize = 0;
        this->lruCache = new Cache();
    }
    
    int get(int _key) 
    {
        cout << "Debug: GET " << _key << endl;  
        int res = this->lruCache->getFromCache(_key);
        this->lruCache->print();
        return res;
    }
    
    void put(int _key, int _value) 
    {
        cout << "Debug: PUT [" << _key << ": " << _value << "]" << endl;
        if(this->lruCache->getFromCache(_key) != -1) 
        {
            this->lruCache->updateTheKey(_key, _value);
            return;
        }
        cout << "curSize: " << curSize << ", " << capacity << endl; 
        if(curSize+1 > capacity) this->lruCache->removeExpiredEntry();
        this->lruCache->insertIntoCache(_key, _value);
        curSize++;
        this->lruCache->print();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

void fastio(bool read = false) {
    if(read) {
        #ifndef ONLINE_JUGDE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt","w",stderr);
        #endif  
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return;
}

int main() 
{
    fastio(true);
    int capacity;
    cin >> capacity;
    LRUCache* cache = new LRUCache(capacity);
    int opr_cnt;
    cin >> opr_cnt;
    while (opr_cnt--) 
    {
        int operation;
        cin >> operation;
        if( operation == 1 )
        {
            int key, value;
            cin >> key >> value;
            cache->put(key, value);
        }
        else if( operation == 2 )
        {
            int key;
            cin >> key; 
            cache->get(key);
        }
    }    
    return 0;
}