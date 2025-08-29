#include<bits/stdc++.h>
using namespace std;
#define INT_SIZE 32

class node{
public:
  int value;
  node*left;
  node*right;
  node(const int value = INT_MIN){
    this->left = NULL;
    this->right = NULL;
    this->value = value;
  }
};

class trie{
public:
  node*root;
  trie(){
    this->root = new node();
  }
  void insert(int data) {
    node*temp = this->root;
    for(int i = INT_SIZE-1; i >= 0; --i) {
      bool cur = (data & (1<<i))? 1: 0;
      // if current node is 1 we will go to right.
      if(cur) {
        if(temp->right == NULL) {
          temp->right = new node();
        }
        temp = temp->right;
      } else {
        if(temp->left == NULL) {
          temp->left = new node();
        }
        temp = temp->left;
      }
    }
    temp->value = data;
  }
  // void searching the element.
  int search(int data) {
    node*temp = this->root;
    for(int i = INT_SIZE-1; i >= 0; --i) {
      bool cur = (data & (1<<i))? 1: 0;
      if(cur) {
        if(temp->left != NULL){
          temp = temp->left;
        } else {
          temp = temp->right;
        }
      } else {
        if(temp->right != NULL){
          temp = temp->right;
        } else{
          temp = temp->left;
        }
      }
    }
    return temp->value^data;
  }
};

vector<int> result;

void buildTable(int *arr,int n){
    trie t;
    vector<int> res(n);
    t.insert(0);
    int pre_xor = 0;
    for(int i = n-1; i >= 0; --i) {
      pre_xor ^= arr[i];
      t.insert(pre_xor);
      if(i==n-1){
        res[i] = pre_xor;
      } else {
        res[i] = max(res[i+1],t.search(pre_xor));
      }
    }
    result = res;
}

int main(){
  #ifndef ONLINE_JUGDE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  freopen("error.txt","w",stderr);
  #endif  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  trie t;
  t.insert(0);
  int *arr = new int[n]();
  for(int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  buildTable(arr,n);
  int pre_xor = 0;
  int ans = INT_MIN;
  int x1 = INT_MIN;
  int x2;
  for(int i = 0; i < n-1; ++i) {
    pre_xor ^= arr[i];
    t.insert(pre_xor);
    x1 = max(x1,t.search(pre_xor));
    x2 = result[i+1];
    ans = max(ans,(x1+x2));
  }
  cout << ans << endl;
  return 0;
}


// Sample Input :

// 4
// 1 2 3 4
// 4
// 8 2 1 12
// 4 
// 1 2 6 8

// Sample Output :

// 10
// 23
// 17