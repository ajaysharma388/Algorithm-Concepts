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

int main() {
    fastio(true);
    int n, x;
    cin >> n >> x;
    int arr[n]; 
    for(int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }   
    
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


/*

Sample Testcase:

10 18
1 2 3 4 5 6 7 8 9 10

Sample Output:

Pair found: 8, 10



*/