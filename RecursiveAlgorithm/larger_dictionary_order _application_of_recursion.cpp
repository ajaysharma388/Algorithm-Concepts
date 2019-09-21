#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

void permute(string in,string out,int i){
    if(out[i]=='\0' && out<in){
        cout << out << endl;
        return;
    }
    for(int j=i;out[j]!='\0';++j){
        swap(out[i],out[j]);
        permute(in,out,i+1);
    }
}

int main(){
    #ifndef ONLINE_JUGDE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif  
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str,ostr;
    cin >> str;
    ostr = str;
    permute(str,ostr,0);
    return 0;
}
