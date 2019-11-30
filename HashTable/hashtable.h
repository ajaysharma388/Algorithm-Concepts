#include <bits/stdc++.h>
#include "prime.h"
using namespace std;

template<typename T>
class node{
public:
	string key;
	T value;
	node<T> *next;
	node(string key,T value){
		this->key = key;
		this->value = value;
	}
	// this is recursive destructor.
	~node(){
		if(next!=NULL){
			delete next;
		}
	}
};

template<typename T>
class HashTable{
	int cs;  // current size.
	int ts;  // total size.
	node<T>** buckets;
	int HashFn(const string key){
		int l = key.length();
		int p = 1; // as 37^0 is 1.
		int ans = 0;
		for(int i=0;i<l;++i){
			// ans+=key[i]*p; // instead of that.
			ans+=key[l-i-1]*p;  // we can also use that.
			p*=37;
			p%=ts;
			ans%=ts;
		}
		return ans;
	}
	void rehash(){
		node<T>** oldBuckets = buckets;
		int oldTs = ts;
		prime p(ts); // you can also do 2*ts.
		cs = 0;
		ts = p.getNextPrime();
		buckets = new node<T>*[ts];
		for(int i=0;i<ts;++i){
			buckets[i] = NULL;
		}	
		// Read from old table and set the data into new bucket.
		for(int i=0;i<oldTs;++i){
			node<T>* temp = oldBuckets[i];
			// copying the data from oldBucket row into buckets.
			if(temp!=NULL){
				while(temp!=NULL){
					insert(temp->key,temp->value);
					temp = temp->next;
				}
				// Delete the oldBuckets row.
				delete oldBuckets[i];
			}
		}
		delete []oldBuckets;
	}
public:
	HashTable(int ds = 7){
		cs = 0;
		ts = ds;
		buckets = new node<T>*[ts];
		// Make all addresses point to NULL.
		for(int i=0;i<ts;++i){
			buckets[i] = NULL;
		}
	}
	void insert(const string key,const T value){
		// key is needed first for having the hash index.
		int index = HashFn(key);
		node<T>* n = new node<T>(key,value);
		n->next = buckets[index];
		buckets[index] = n;
		cs++;
		float load_factor = (float) cs/ts;
		if(load_factor>0.85){
			cout << " load factor is : " << load_factor << endl;
			rehash();
		}
	}

	void print(){
		// we can iterate over the buckets array.
		for (int i = 0; i < ts; ++i){
			cout<<i+1<<" . bucket ["<<i<<"] => ";
			// Print Linked List for each bucket.
			node<T>*temp = buckets[i];
			while(temp!=NULL){
				cout<<temp->key<<" ";
				temp = temp->next;
			}
			cout<<endl;
		}
	}

	T* search(const string key){
		int index = HashFn(key);
		// now iterate over the linked List inside the bucket.
		node<T>* temp = buckets[index];
		while(temp!=NULL){
			if(temp->key == key){
				return &(temp->value);
			}
			temp = temp->next;
		}
		return NULL;
	}

	void Delete(const string key){
		int index = HashFn(key);
		// now iterate over the list inside bucket to remove
		// the content.
		node<T>* cur = buckets[index];
		node<T>* pre = NULL;
		while(cur!=NULL){
			if(cur->key == key && pre!=NULL){
				pre->next = cur->next;
				delete cur;
				return;
			}
			if(cur->key == key && pre==NULL){
				buckets[index] = cur->next;
				delete cur;
				return;
			}
			pre = cur;
			cur = cur->next;
		} 
	}
};