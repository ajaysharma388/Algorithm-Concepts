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

#define TaskInfo pair<int, char>

class Solution 
{
public:
	int leastInterval(vector<char>& tasks, int n) 
    {
    	fastio();
    	vector<int> cnt(26, 0);
    	for(char task: tasks)
    		cnt[task-'A']++;
    	priority_queue<TaskInfo> pq;
    	for(int i = 0; i < 26; ++i)
    		if(cnt[i]) pq.push({cnt[i], (char)('A'+i)});
       	int res = 0;
    	// now simply iterate over the data in queue and execute 
    	// them in order.
    	while(!pq.empty())
    	{
    		vector<TaskInfo> cur;
    		for(int i = 0; i <= n; ++i)
    			if (!pq.empty()) 
    			{
	    			cur.push_back(pq.top());
	    			pq.pop();
	    		}
    		for(TaskInfo task: cur)
    			if(--task.first) pq.push(task);
    		
    		res += !pq.empty() ? n+1 : cur.size();
    	}
    	return res;
    }

    void solve()
    {
    	int n, k;
    	cin >> n >> k;
    	vector<char> tasks(n, '\0');
    	for(int i = 0; i < n; ++i)
    		cin >> tasks[i];
    	cout << leastInterval(tasks, k) << endl;
    }
};

int main() 
{
    fastio(true);
    int tc;
    cin >> tc;
    for(int i = 1; i <= tc; ++i) 
    {    
    	Solution *s = new Solution();
    	cout << "TestCase #" << i << " : ";
    	s->solve();        
    }
    return 0;
}

/*

Sample Input:

3
6 2 A A A B B B
6 1 A C A B D B 
6 3 A A A B B B

Sample Output:

TestCase #1 : 8
TestCase #2 : 6
TestCase #3 : 10

*/

