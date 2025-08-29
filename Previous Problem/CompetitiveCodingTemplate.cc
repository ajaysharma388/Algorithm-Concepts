#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define fileio freopen("http://in.in", "r", stdin),freopen("out.out", "w", stdout);
#define ll long long
#define ld long double
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pll pair<long long ,long long >
#define ppll pair < pll , pll >
#define sd(x) scanf("%d",&x)
#define sld(x) scanf("%lld",&x)
#define INF 1e18
#define eps 0.00001
#define le length
#define debug(n1) cout << n1 << endl
#define rep(i , j , n) for(ll i = j ; i <= n ; i++)
#define per(i , j , n) for(ll i = j ; i >= n ; i--)
const ll N = 3e5 + 5;
const ll MAX = 3e5 + 5;
const ll M = 1e6 + 5;
const int mod = 1e18 + 7;
ll MODULAR_POWER(ll a , ll b , ll MOD) {
    if(b == 0) return 1LL;
    ll d = MODULAR_POWER(a , b / 2 , MOD);
    d *= d;
    d %= MOD;
    if(b % 2) d *= a;
    d %= MOD;
    return d;
}
ll BINARY_SEARCH(ll dp[] , ll n , ll key) {
    ll s = 1;
    ll e = n;
    while(s <= e) {
        ll mid = (s + e) / 2;
        if(dp[mid] == key) return mid;
        else if (dp[mid] > key) e = mid - 1;
        else s = mid + 1;
    }
    return -1;
}
string CONVERT_TO_BINARY(ll s) {
    string res = "";
    while(s != 0) {
        res += (char)('0' + s % 2);
        s /= 2;
    }
    reverse(res.begin() , res.end());
    return res;
}
bool PALIN(string s) {
    ll i = 0;
    ll j = s.le() - 1;
    while(i <= j) {
        if(s[i] != s[j]) return false;
        j-- , i++;
    }
    return true;
}
ll STOI(string s) {
    ll num = 0;
    ll po = 1;
    per(i , s.le() - 1 , 0) {
        num += po * (s[i] - '0');
        po *= 10;
    }
    return num;
}
int main() {
    SPEED;
    cout.precision(8);
    cout << fixed;
 
    return 0;
}