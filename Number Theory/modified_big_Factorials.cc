#include <iostream>
using namespace std;

int fac(int *a,int num,int m){
    int carry=0;
    for(int i=0;i<=m;++i){
        int res=a[i]*num+carry;
        a[i]=res%10;
        carry=res/10;
    }
    while(carry){
        m++;
        a[m]=carry%10;
        carry/=10;
    }
    return m;
}

int main(){
    int testCases;
    cin>>testCases;
    while(testCases--){
        int n;
        cin>>n;
        int a[200],m=0;
        a[0]=1;
        for(int i=2;i<=n;++i)
            m=fac(a,i,m);
        for(int i=m;i>=0;i--)
            cout<<a[i];
        cout<<endl;
    }
    return 0;
}