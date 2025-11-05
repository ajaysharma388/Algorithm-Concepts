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

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

int main()
{
    fastio();
    while(1)
    {
        char c = getchar(); 
        cout << c << " " << c-'a' << endl;
        switch(c-'a') 
        {
            case KEY_UP:
                cout << endl << "Up" << endl;//key up
                break;
            case KEY_DOWN:
                cout << endl << "Down" << endl;   // key down
                break;
            case KEY_LEFT:
                cout << endl << "Left" << endl;  // key left
                break;
            case KEY_RIGHT:
                cout << endl << "Right" << endl;  // key right
                break;
            default:
                cout << endl << "null" << endl;  // not arrow
                break;
        }
    }

    return 0;
}