#include <bits/stdc++.h>
using namespace std;

int partition(int a[],int s,int e){
    int i=s-1,j=s,pivot=a[e];
    for(;j<e;j++){
        if(a[j]<=pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[e]);
    return i+1;
}

void quick_Sort(int a[],int s,int e){
    if(s>=e) return;
    int pivot=partition(a,s,e);
    quick_Sort(a,s,pivot-1);
    quick_Sort(a,pivot+1,e);
}

void randomised(int a[],int s,int e){
    srand(time(NULL));
    int j;
    for(int i=e;i>0;i--){
        j=rand()%(i+1);
        swap(a[i],a[j]);
    }
}
int main(){
    #ifndef ONLINE_JUGDE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    randomised(a,0,n-1);
    quick_Sort(a,0,n-1);
    for(int i=0;i<n;++i){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}

// The worst case time complexity of this algorithm is O( n2 ),
// but as this is randomized algorithm, 
// its time complexity fluctuates between O(n^2) 
// and O(n (log n) ) and mostly it comes out to be O( n (log n)) .