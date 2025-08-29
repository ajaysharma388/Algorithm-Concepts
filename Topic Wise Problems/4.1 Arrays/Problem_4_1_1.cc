// 1.  Find a pair in an array of size 'n', whose sum is X

#include <bits/stdc++.h>
using namespace std;   

int main() {
    int n, x;
    cin >> n >> x;
    int arr[n]; 

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }   
    sort(arr, arr + n);
    int left = 0, right = n - 1;
    bool found = false;     
    while(left < right) {
        int sum = arr[left] + arr[right];
        if(sum == x) {
            found = true;
            cout << "Pair found: " << arr[left] << ", " << arr[right] << endl;
            break;
        }       
        else if(sum < x) {
            left++;
        }
        else {
            right--;
        }           
    }
    if(!found) {
        cout << "No such pair found" << endl;
    }
    return 0;
}   
