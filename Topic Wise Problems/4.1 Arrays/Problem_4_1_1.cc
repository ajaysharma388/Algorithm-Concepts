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

void find_pair_without_extra_space(vector<int> &arr, int n, int key)
{
    int left = 0, right = n - 1;
    bool found = false;     
    while(left < right) {
        int sum = arr[left] + arr[right];
        if(sum == key) {
            found = true;
            cout << "Pair found: " << arr[left] << ", " << arr[right] << endl;
            break;
        }       
        else if(sum < key) {
            left++;
        }
        else {
            right--;
        }           
    }
    if(!found) {
        cout << "No such pair found" << endl;
    }
}

void find_pair_using_extra_space(vector<int> &nums, int n, int key)
{
    unordered_map<int, int> mp;
    for(int i = 0; i < n; ++i)
    {
        if ( mp.count(key-nums[i]) )
        {
            cout << "Pair found: " << nums[i] << ", " << nums[mp[key-nums[i]]] << endl;
            return;
        }
        mp[nums[i]] = i;
    }
    cout << "No such pair found" << endl;
}

int main() {
    fastio(true);
    int n, x;
    cin >> n >> x;
    vector<int> arr(n, 0); 
    for(int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }   
    find_pair_without_extra_space(arr, n, x);
    find_pair_using_extra_space(arr, n, x);
    return 0;
}   


/*
Sample Testcase:

10 18
1 2 3 4 5 6 7 8 9 10

Sample Output:

Pair found: 8, 10
*/