#include <bits/stdc++.h>
using namespace std;

class StackUsingQueue{
    queue<int> *q1, *q2;
    public:
        StackUsingQueue(){
            q1 = new queue<int>();
            q2 = new queue<int>();
        }
        void push(int x){
            q1->push(x);     // O(1)
        }
        void pop(){
            int n = q1->size();
            // pop n-1 elements from q1 to q2
            for(int i = 0; i < n - 1; ++i){
                q2->push(q1->front());
                q1->pop();
            }
            
            if (q1->empty() == false) {
                q1->pop();
                swap(q1, q2);   // maintain definition that q2 is always empty
            }

        }
        int top(){
            int n = q1->size();
            // pop n-1 elements from q1 to q2
            for(int i = 0; i < n - 1; ++i){
                q2->push(q1->front());
                q1->pop();
            }
            int topElement = q1->front();
            if (q1->empty() == false) {
                q2->push(q1->front());
                q1->pop();
                swap(q1, q2);   // maintain definition that q2 is always empty
            }
            return topElement;
        }
        ~StackUsingQueue(){
            delete q1;
            delete q2; 
        }
};

int main(){
    #ifndef ONLINE_JUGDE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    StackUsingQueue s;
    for(int i=1;i<=10;++i) s.push(i*i);
    cout << s.top() << " ";
    cout << s.top() << " ";
    s.pop();
    cout << s.top();    
    return 0;
}

