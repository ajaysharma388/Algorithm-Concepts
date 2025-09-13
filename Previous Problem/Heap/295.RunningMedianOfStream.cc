#include <bits/stdc++.h>
using namespace std;

void fastio(bool read = false) 
{
    if(read) 
    {
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

#define max_heap priority_queue<int> 
#define min_heap priority_queue<int, vector<int>, greater<int>> 

class MedianFinder 
{
    max_heap minElements;
    min_heap maxElements;
public:
    MedianFinder() { fastio(); }
    
    void addNum(int num) {
        minElements.push(num);
        if(!maxElements.empty() && minElements.top() > maxElements.top())
        {
            maxElements.push(minElements.top());
            minElements.pop();
        }
        if(minElements.size() > maxElements.size()+1)
        {
            maxElements.push(minElements.top());
            minElements.pop();
        }
        if(maxElements.size() > minElements.size()+1)
        {
            minElements.push(maxElements.top());
            maxElements.pop();
        }
    }
    
    double findMedian() {
        if(minElements.size() == maxElements.size())
        {
            return (minElements.top() + maxElements.top())/2.0;
        }
        else if(minElements.size() < maxElements.size())
        {
            return maxElements.top();
        }
        return minElements.top();
    }

    void solve()
    {
        int actionCnt;
        cin >> actionCnt;
        int data;
        while(actionCnt--)
        {
            int ac;
            cin >> ac;
            switch(ac)
            {
                case 1:
                    cin >> data;
                    addNum(data);
                    break;
                case 2:
                    cout << findMedian() << endl;
                    break;
            }
        }
        return;
    }
};

int main() 
{
    fastio();
    int tc;
    cin >> tc;
    for (int test = 1; test <= tc; ++test) 
    {    
        MedianFinder *s = new MedianFinder();
        cout << "TestCase #" << test << ": ";
        s->solve();        
    }
    return 0;
}

/*

Sample Input:

1
6
1 1
2
1 2
2
1 3
2

Sample Output:

TestCase #1: 
1
1.5
2

*/
