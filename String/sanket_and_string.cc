#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

int main(){
    #ifndef ONLINE_JUGDE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif  
    int m=0,n,i=0,j=0,count;  
    string s;
    cin >> n >> s;
    int l = s.length();
    for(;j<l;j++){
        count = 0;
        i=j;
        while(i<l){
            if(s[i]=='b') count++;
            if(count>n) break;
            i++;
        }
        m = max(m,i-j);
    }
    cout<<m<<endl;
    return 0;
}