#include <bits/stdc++.h>
using namespace std;

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

class Node
{
public:
    int key;
    int data;
    int access;
    Node* prev;
    Node* next;
    Node()
    {
        this->key = INT_MIN;
        this->data = INT_MIN;
        this->access = INT_MIN;
        this->prev = nullptr;
        this->next = nullptr;
    }

    Node(int key, int data)
    {
        this->key = key;
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
        this->access = 1;
    }

    void updateNode(int data)
    {
        this->access++;
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};


class LFUCache 
{
    map<int, pair<Node*, Node*>> freqList;
    unordered_map<int, Node*> cacheInfo;
    int capacity;
    int curSize;

    void print()
    {
        cout << "Start::Print\n\n";
        for(auto list: freqList)
        {
            cout << "Freq :" << list.first << " => ";
            Node* start = list.second.first;
            while(start != list.second.second)
            {
                cout << "[" << start->key << ", " << start->data << ", " << start->access << " ] , ";
                start = start->next;
            }
            cout << "[" << list.second.second->key << ", " << list.second.second->data << ", " << list.second.second->access << " ]\n";
            start = list.second.second;
            while(start != list.second.first)
            {
                cout << "[" << start->key << ", " << start->data << ", " << start->access << " ] , ";
                start = start->prev;
            }
            cout << "[" << list.second.first->key << ", " << list.second.first->data << ", " << list.second.first->access << " ]\n";
        }
        cout << "\nEnd::Print\n*************\n";
    }



    void addIntoCache(Node* cacheObject, int idx = 1)
    {
        // first check if there are any entry with freq 1.
        bool isAvailable = freqList.find(idx) != freqList.end();
        if(!isAvailable) 
        {
            freqList[idx].first = nullptr;
            freqList[idx].second = nullptr;
        }  
        // cout << "Adding key : " << cacheObject->key << " " << cacheObject->data << endl;
        if(freqList[idx].first == nullptr && freqList[idx].second == nullptr)
        {

            freqList[idx].first = cacheObject;
            freqList[idx].second = cacheObject;
        }
        else
        { 
            cacheObject->next = freqList[idx].first;
            freqList[idx].first->prev = cacheObject;
            freqList[idx].first = cacheObject;    
        }
        if(idx == 1) curSize++;
        // print();
    }


    void cleaupTheCache()
    {
        int minFreqToRemove = (*freqList.begin()).first;
        Node* curNode = freqList[minFreqToRemove].second;
        // cout << "Removing the Node : [" << curNode->key << ", " << curNode->data << ", " << curNode->access << " ]\n";
        invalidataCache(curNode->key, curNode->data, false);
    }

    void invalidataCache(int key, int value, bool adding = true)
    {
        Node* curNode = cacheInfo[key];
        int idx = curNode->access;
        // if this is middle node.
        if(curNode->next && curNode->prev)
        {
            curNode->next->prev = curNode->prev;
            curNode->prev->next = curNode->next; 
        }
        else if(curNode->prev == nullptr) // if this is a head node.
        {
            freqList[idx].first = curNode->next;
            if(curNode->next == nullptr)
            {
                freqList[idx].first = nullptr;
                freqList[idx].second = nullptr;
                freqList.erase(idx);
            }
            else
            {
                freqList[idx].first->prev = nullptr;
            }
        }
        else if(curNode->next == nullptr) // this is a tail node.
        {   
            // cout << "Node End " << curNode->key << ": " << curNode->data << ", " << curNode->access << endl;
            freqList[idx].second = curNode->prev;
            if(freqList[idx].second)
            {
                freqList[idx].second->next = nullptr;
            }
        }
        // Now re add the node into the appropriate freqList.
        if(adding)
        {
            curNode->updateNode(value);
            addIntoCache(curNode, curNode->access);
        }
        else
        {
            cacheInfo.erase(curNode->key);
            delete curNode;
        }
    }   

public:
    LFUCache(int capacity) 
    {
        fastio();
        this->capacity = capacity;
        this->curSize = 0;
    }
    
    int get(int key) 
    {
        bool isPresent = cacheInfo.find(key) != cacheInfo.end();
        int res = -1;
        if(isPresent)
        {
            Node* curNode = cacheInfo[key];
            invalidataCache(curNode->key, curNode->data);
            res = curNode->data;
        }
        return res;
    }
    
    void put(int key, int value) 
    {
        // logic:
        // 1. it should update the key if this is present in the cache.
        // 2. if the key is not present then we need to add the key into cache.
        // After adding we need to validate if curSize has out grown capacity
        // 1. then we have to invalidate or remove the key that is least freq used.
        // 2. if there is a tie between the nodes then it should remove the least recently used.
        bool isPresent = cacheInfo.find(key) != cacheInfo.end();
        if(isPresent)
        {
            invalidataCache(key, value);
        }
        else
        {
            // key is not present.
            cacheInfo[key] = new Node(key, value);
            if(curSize+1 > capacity)
            {
                cleaupTheCache();
            }
            addIntoCache(cacheInfo[key]);
        }
    }
};


void solve()
{
    int sz, n;
    cin >> sz >> n;
    LFUCache *cache = new LFUCache(n);
    while(n--)
    {
        int cmd;
        cin >> cmd;
        if(cmd == 1)
        {
            int key, value;
            cin >> key >> value;
            cache->put(key, value);
        }
        else 
        {
            int key;
            cin >> key;
            cout << "Read Key " << key << endl;
            int val = cache->get(key);
            cout << "Key : " << key << " => "<< val << endl;
        }
    }

}


int main()
{
    int n;
    cin >> n;
    fastio();
    for(int i = 1; i <= n; ++i)
    {
        cout << "TestCase #" << i << "\n";
        solve();
    }
    return 0;
}


/*

Sample Input:

1
5 20
1 1 1
1 2 2
1 3 3
1 1 111
1 4 5
1 5 6
1 7 10
1 7 7
1 5 11
1 1 1111
1 7 7777
1 5 5555
2 1
2 6
2 7
2 5
1 4 5
2 4
1 4 4444
2 4

Sample Output:

TestCase #1
Read Key 1
Key : 1 => 1111
Read Key 6
Key : 6 => -1
Read Key 7
Key : 7 => 7777
Read Key 5
Key : 5 => 5555
Read Key 4
Key : 4 => 5
Read Key 4
Key : 4 => 4444

*/