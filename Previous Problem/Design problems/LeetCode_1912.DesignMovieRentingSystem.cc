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

class MovieRentingSystem 
{
	int shopsCount;
	unordered_map<int, set<pair<int, int>>> unrentedMovies;
	unordered_map<int, set<pair<int, int>>> rentedMovies;
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) 
    {
    	this->shopsCount = n;
    	for(vector<int> entry: entries)
		{
			cout << entry[1] << " : (" << entry[2] << ", " << entry[0] << ")\n";
			this->unrentedMovies[entry[1]].insert({entry[2], entry[0]}); 
		}
	}
    
    vector<int> search(int movie) 
    {
    	vector<int> res;
    	// if the movie is not available we will return the empty list;
    	if(unrentedMovies.find(movie) == unrentedMovies.end()) return res;
    	for(auto it = unrentedMovies[movie].begin(); it != unrentedMovies[movie].end(); ++it)
    	{
    		res.emplace_back((*it).second);
    		if(res.size() == 5) break;
    	}
    	return res;
    }
    
    void rent(int shop, int movie) 
    {
        
    }
    
    void drop(int shop, int movie) {
        
    }
    
    vector<vector<int>> report() {
        return {{}};
    }
};

void print(int m, vector<int> shops)
{
	cout << "Start\nMovie " << m << " Found in Below shops\n[";
	for(int s : shops)
	{
		cout << s << " ";
	}
	cout << "]\n\nEnd\n";
}

void solve()
{
	int n, k;
	cin >> n >> k;
	vector<vector<int>> entries;
	while(k--)
	{
		int si, mi, ri;
		cin >> si >> mi >> ri;
		entries.push_back({si, mi, ri});
	}
	MovieRentingSystem *s = new MovieRentingSystem(n, entries);
	int x;
	cin >> x;
	while(x--)
	{
		int ac;
		cin >> ac;
		switch(ac)
		{
			case 1:
				int m;
				cin >> m;
				print(m, s->search(m));
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
		}
	}
    return;
}

int main() 
{
    fastio(true);
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t) 
    {    
        cout << "TestCase #" << t << " : " << endl;
        solve();        
    }
    return 0;
}

/*

Sample Input:

1
3 6
0 1 5
0 2 6 
0 3 7
1 1 4
1 2 7 
2 1 5
6
1 1
2 0 1 
2 1 2
3
4 1 2
1 2


Sample Output:




*/
