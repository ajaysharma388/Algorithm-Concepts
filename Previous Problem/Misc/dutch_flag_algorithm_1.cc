#include <iostream>
using namespace std;

void dutch_flag_algo(int a[],int n){
    int s=0,mid=0,e=n-1;
    while(mid<=e){
        if(a[mid]==1) mid++;
        else if(a[mid]==2){
            swap(a[mid],a[e]);
            e--;
        }else{
            swap(a[mid],a[s]);
            s++; mid++;
        }
    }
    return;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    dutch_flag_algo(a,n);
    for(int i=0;i<n;++i){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}