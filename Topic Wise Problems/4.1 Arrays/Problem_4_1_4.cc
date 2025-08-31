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
    for(int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }   
    int max_number = 1;

    sort(arr.begin(),arr.end());

    for(int i =  0; i < n; i++)
    {
    	if(arr[i] == arr[i + 1])
    	{
    		max_number++;

    	}
    	else{
    		if(max_number % 2 != 0)
    		{	
    		cout<<arr[i] << " Appearing "<< max_number<<" Times"<< endl;
    		}
    		max_number = 1;
    	}
    }
    
    return 0;
}   


/*

4.  Find the number occuring odd number of times in a given array of size 'n'

Sample Testcase:

10 
1 2 2 3 3 3 3 4 5 6

Sample Output:

1 Appearing 1 Times
4 Appearing 1 Times
5 Appearing 1 Times
6 Appearing 1 Times

*/