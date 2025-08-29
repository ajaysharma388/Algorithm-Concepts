#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define s string

int isSubstring(string s1, string s2){ 
    int M = s1.length(); 
    int N = s2.length();
    if(N>M) 
        for (int i = 0; i <= N - M; i++) { 
            int j; 
            for (j = 0; j < M; j++) 
                if (s2[i + j] != s1[j]) 
                    break;   
            if (j == M) 
                return i; 
        }
    else
        for (int i = 0; i <= M-N; i++) { 
            int j; 
            for (j = 0; j < N; j++) 
                if (s1[i + j] != s2[j]) 
                    break;   
            if (j == N) 
                return i; 
        }
    return -1; 
} 

bool compare(s s1,s s2){
    if(isSubstring(s1,s2)==-1)
        return s1<s2;
    else
        return s1.length()>s2.length();
}

int main(){
    int n;
    cin>>n;
    s a[n];
    for(int i=0;i<n;++i)
        cin>>a[i];
    sort(a,a+n,compare);
    for(int i=0;i<n;++i)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}