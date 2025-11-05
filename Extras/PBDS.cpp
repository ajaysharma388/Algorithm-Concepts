
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef pair<int, int> pii;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


int main() 
{
    fastio(true);
    
	ordered_set os;
	os.insert({1, 2});
	os.insert({3, 4});

	cout << os.order_of_key({3, 4}) << endl;       // Number of elements < {3, 4}
	cout << os.find_by_order(0)->first << endl;    // First element

    return 0;
}