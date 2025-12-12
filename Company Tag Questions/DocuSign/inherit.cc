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

class Parent {
public:
    virtual void introduce() = 0;
    virtual void printName()
    {
        cout << "My Name is Parent" << endl;
    }
};

class A: public Parent {
public:
    void introduce() {
        printName("A Class");
    }

    void printName(string str)
    {
        cout << "My Name is " << str << endl;
    }
};

class B: public Parent {
    public:
    void introduce() {
        printName("B Class");
    }

    void printName(string str)
    {
        cout << "My Name is " << str << endl;
    }
};


class child: public A, public B {
    public:
    void introduce() {
        printName("child Class");
    }

    void printName(string str)
    {
        cout << "My Name is " << str << endl;
    }
};

class Solution 
{
public:
    void solve()
    {
        child *ch1 = new child();
        A *ch2 = new child();
        B *ch3 = new child();
        ch1->introduce();
        ch2->introduce();
        ch3->introduce();   
    }
};

int main() 
{
    fastio(true);
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t) 
    {    
        Solution *s = new Solution();
        cout << "TestCase #" << t << " : \n";
        s->solve();        
    }
    return 0;
}

/*
Sample Input:

Sample Output:

*/