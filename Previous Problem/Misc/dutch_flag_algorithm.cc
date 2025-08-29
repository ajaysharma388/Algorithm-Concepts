#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }   
    int low=0,hi=n-1,mid=0;
    while(mid<hi){
        if(arr[mid]==1){
            mid++;
        }else if(arr[mid]==2){
            swap(arr[mid],arr[hi]);
            hi--;
        }else{
            swap(arr[mid],arr[low]);
            mid++;
            low++;
        }
    }
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}