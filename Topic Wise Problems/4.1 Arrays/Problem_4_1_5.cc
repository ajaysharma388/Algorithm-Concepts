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
    int n;
    cin >> n ;
    std::vector<int> arr(n, 0);
     std::stack<int> st;
    for(int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    
    }
     for(int i = 0; i < n; i++) 
    {
        st.push(arr[i]);
    }
    while (!st.empty()) {
        cout << " "<< st.top();
        st.pop();
    }

    // for(int i = n - 1; i >= 0; i--)
    // {
    // 	cout<<arr[i] <<" ";
    // }

    // int left = 0; int right = n - 1;
    // while(left<=right)
    // {
    // 	swap(arr[left],arr[right]);
    // 	left++;
    // 	right--;
    // }
    // for(int i = 0; i < n; i++)
    // {
   	// 	cout<<arr[i] <<" ";
    // }
    return 0;
}   


/*

5.  Algorithm to reverse an array

Sample Testcase:

10 
1 2 3 4 5 6 7 8 9 10

Sample Output:
10 9 8 7 6 5 4 3 2 1 

*/