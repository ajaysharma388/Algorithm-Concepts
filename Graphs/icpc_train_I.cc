#include <bits/stdc++.h>
 
#define ll long long
#define pb push_back
#define endl '\n'
 
using namespace std;

template<typename ... T> void shit(T& ... x){}
template<typename ... T> void dec(T& ... x){shit(--x...);}
template<typename ... T> void inc(T& ... x){shit(++x...);}

const int inf = 1e9;
const double eps = 1e-9;
const int maxn = 1e5 + 10, base = 1e9 + 7;
const int l = 19;

vector<int> g[maxn];
int tin[maxn], tout[maxn], width[maxn];
int timer = 0;
int up[maxn][l + 5];

void dfs (int v, int p, int w = 0) {
    tin[v] = ++timer;
    up[v][0] = p;
    width[v] = w;

    for (int i = 1; i <= l; i++)
        up[v][i] = up[ up[v][i - 1] ][i - 1];

    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (to != p)
            dfs (to, v, w + 1);
    }

    tout[v] = ++timer;
}

bool parent (int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca (int a, int b) {
    if (parent (a, b))
        return a;
    if (parent (b, a))
        return b;

    for (int i = l; i >= 0; i--)
        if (!parent (up[a][i], b))
            a = up[a][i];

    return up[a][0];
}

vector<pair<int, int> > tree[8];

int dist(int a, int b)
{
    int curLca = lca(a, b);
    return width[a] - width[curLca] + width[b] - width[curLca];
}

ll dp[8][8][8], d[8][8];

struct State
{
    int v[3];
    State(){}
    State(int v0, int v1, int v2){
        v[0] = v0;
        v[1] = v1;
        v[2] = v2;
    }
};

int main()
{
    int n, a, b, c, v[3];
    scanf("%d", &n);
    scanf("%d %d %d", &a, &b, &c);

    scanf("%d %d %d", &v[0], &v[1], &v[2]);
    dec(v[0], v[1], v[2]);

    for (int i = 1; i < n; i++){
        int f, to;
        scanf("%d %d", &f, &to);
        f--, to--;
        g[f].pb(to);
        g[to].pb(f);
    }

    dfs(0, 0);
    
    vector<int> need(1, 0);

    for (int i = 0; i < 3; i++){
        need.pb(v[i]);
    }

    for (int i = 0; i < 3; i++){
        for (int j = i + 1; j < 3; j++){
            need.pb(lca(v[i], v[j]));
        }
    } 
    need.pb(lca(v[0], lca(v[1], v[2])));

    for (int i = 0; i < need.size(); i++)
        for (int j = i + 1; j < need.size(); j++){
            d[j][i] = d[i][j] =  dist(need[i], need[j]);
        }

    memset(dp, 63, sizeof(dp));
    dp[1][2][3] = 0;

    queue<State> q;

    q.push(State(1, 2, 3));

    while(!q.empty()){
        State front = q.front();
        q.pop();
            int v0 = front.v[0];
            int v1 = front.v[1];
            int v2 = front.v[2];

        for (int to = 0; to < 8; to++){
            ll curdist = (ll)d[to][v0] * a + dp[v0][v1][v2];
            if (dp[to][v1][v2] > curdist){
                dp[to][v1][v2] = curdist;
                q.push(State(to, v1, v2));
            }
                curdist = (ll)d[to][v1] * a + dp[v0][v1][v2];
            if (dp[v0][to][v2] > curdist){
                dp[v0][to][v2] = curdist;
                q.push(State(v0, to, v2));
            }
                curdist = (ll)d[to][v2] * a + dp[v0][v1][v2];
            if (dp[v0][v1][to] > curdist){
                dp[v0][v1][to] = curdist;
                q.push(State(v0, v1, to));
            }

                curdist = (ll)d[to][v0] * b + dp[v0][v1][v2];
            if (v0 == v1 && dp[to][to][v2] > curdist){
                dp[to][to][v2] = curdist;
                q.push(State(to, to, v2));
            }
            if (v0 == v2 && dp[to][v1][to] > curdist){
                dp[to][v1][to] = curdist;
                q.push(State(to, v1, to));
            }
                curdist = (ll)d[to][v1] * b + dp[v0][v1][v2];
            if (v1 == v2 && dp[v0][to][to] > curdist){
                dp[v0][to][to] = curdist;
                q.push(State(v0, to, to));
            }

                curdist = (ll)d[to][v0] * c + dp[v0][v1][v2];
            if (v0 == v1 && v1 == v2 && dp[to][to][to] > curdist){
                dp[to][to][to] = curdist;
                q.push(State(to, to, to));
            }
        }
    }
    
    cout << dp[0][0][0];
    return 0;
}