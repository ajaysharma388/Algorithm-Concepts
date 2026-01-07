#include <bits/stdc++.h>
using namespace std;

void fastio(bool read = false) 
{
    if(read) 
    {
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

class Solution 
{
public:
	void getPosibleMoves(int n, int &cnt, char from, char via, char to)
	{
		// now first move the first n-1 plates from rack to via rack.
		if(n == 0) return;
		getPosibleMoves(n-1, cnt, from, to, via);
		cnt += 1;
		cout << "Moving disk from " << from << " -> " << to << endl;
		getPosibleMoves(n-1, cnt, via, from, to);
	}

    int solve()
    {
       int n, cnt = 0;
       cin >> n;
       getPosibleMoves(n, cnt, 'A', 'B', 'C');
       return cnt;
    }
};

int main() 
{
    fastio(true);
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t) 
    {    
        Solution *s = new Solution();
        cout << "TestCase #" << t << " : \n" << s->solve() << endl;        
    }
    return 0;
}

/*
Sample Input:

4
1
2
3
4

Sample Output:

TestCase #1 : 
Moving disk from A -> C
1
TestCase #2 : 
Moving disk from A -> B
Moving disk from A -> C
Moving disk from B -> C
3
TestCase #3 : 
Moving disk from A -> C
Moving disk from A -> B
Moving disk from C -> B
Moving disk from A -> C
Moving disk from B -> A
Moving disk from B -> C
Moving disk from A -> C
7
TestCase #4 : 
Moving disk from A -> B
Moving disk from A -> C
Moving disk from B -> C
Moving disk from A -> B
Moving disk from C -> A
Moving disk from C -> B
Moving disk from A -> B
Moving disk from A -> C
Moving disk from B -> C
Moving disk from B -> A
Moving disk from C -> A
Moving disk from B -> C
Moving disk from A -> B
Moving disk from A -> C
Moving disk from B -> C
15


*/