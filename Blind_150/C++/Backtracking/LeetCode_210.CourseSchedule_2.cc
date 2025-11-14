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

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adjList;
        vector<int> indegree(numCourses, 0);
        for(vector<int> edge: prerequisites)
        {
            int dest = edge[0], src = edge[1];
            adjList[src].push_back(dest);
            indegree[dest] += 1;
        }
        queue<int> Q;
        vector<int> res;
        for(int i = 0; i < numCourses; ++i)
            if (!indegree[i]) Q.push(i);
        while(!Q.empty())
        {
            for(int i = 0; i < Q.size(); ++i)
            {
                int cur = Q.front();
                Q.pop();
                res.push_back(cur);
                for(int nbr: adjList[cur])
                {
                    indegree[nbr] -= 1;
                    if(indegree[nbr] == 0) Q.push(nbr);
                }
            }
        }
        for(int i = 0; i < numCourses; ++i)
            if(indegree[i]) return vector<int>();
        return res;
    }

    void solve()
    {
    	int numCourses, edge;
    	cin >> numCourses >> edge;
    	vector<vector<int>> prerequisites;
    	for(int i = 0; i < edge; i++)
    	{
    		int src, dest;
    		cin >> dest >> src;
    		prerequisites.push_back({dest, src});
    		vector<int> res = findOrder(numCourses, prerequisites);
    		for(int node: res)
    		{
    			cout << node << ", ";
    		}
    		cout << endl;
    	}
        return;
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
        cout << "TestCase #" << t << " : " << endl;
        s->solve();        
    }
    return 0;
}

/*

Sample Input:


Sample Output:


*/
