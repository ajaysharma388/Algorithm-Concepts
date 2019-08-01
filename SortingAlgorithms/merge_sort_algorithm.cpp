#include <bits/stdc++.h>
using namespace std;

void merge_array(int *a,int s,int e){
    int mid=(s+e)/2,i=s,j=mid+1,k=s;
    int temp[100]={0};
    while(i<=mid && j<=e){
        if(a[i]<a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }
    while(i<=mid){
        temp[k++]=a[i++];
    }
    while(j<=e){
        temp[k++]=a[j++];
    }
    for(int i=s;i<=e;++i)
        a[i]=temp[i];
}

void merge_sort(int a[],int s,int e){
    if(s>=e) return;
    int m=(s+e)/2;
    merge_sort(a,s,m);
    merge_sort(a,m+1,e);
    merge_array(a,s,e);
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
    for(int i=0;i<n;++i)
        cin>>a[i];
    merge_sort(a,0,n-1);
    for(int i=0;i<n;++i)
        cout<<a[i]<<" ";   
    cout<<endl; 
    return 0;
}


//the time complexity of the merge sort algorithm is O(n.log n)