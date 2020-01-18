#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define N 111111
#define INF (1LL<<50)

vector<int> adj[N];
int parent[N];
int depth[N];
ll locs[N];
ll a, b, c;

int lca(int i, int j) {
    while (depth[i] > depth[j]) i = parent[i];
    while (depth[j] > depth[i]) j = parent[j];
    while (i != j) {
        i = parent[i];
        j = parent[j];
    }
    return i;
}

int dist(int i, int j) {
    return depth[i] + depth[j] - 2 * depth[lca(i, j)];
}

ll compute_for(int u, int v, int x, int w, int y) {
    ll cost = 0;
    cost += dist(u, x) * a + dist(v, x) * a;
    cost += dist(x, y) * b + dist(w, y) * a;
    cost += dist(y, 0) * c;
    return cost;
}

void solve() {
    int n;
    int u, v, w;
    scanf("%d%lld%lld%lld%d%d%d", &n, &a, &b, &c, &u, &v, &w);
    for (int i = 0; i < n; i++) {
        adj[i].clear();
        parent[i] = -1;
    }
    u--, v--, w--;
    b = min(b, a + a);
    c = min(c, a + b);
    for (int e = 1; e < n; e++) {
        int i, j;
        scanf("%d%d", &i, &j);
        i--, j--;
        adj[i].push_back(j);
        adj[j].push_back(i);
    }
    vector<int> stack;
    parent[0] = 0;
    depth[0] = 0;
    stack.push_back(0);
    while (!stack.empty()) {
        int i = stack.back(); stack.pop_back();
        for (int j : adj[i]) {
            if (!~parent[j]) {
                parent[j] = i;
                depth[j] = depth[i] + 1;
                stack.push_back(j);
            }
        }
    }
    int k = 0;
    locs[k++] = 0;
    locs[k++] = u;
    locs[k++] = v;
    locs[k++] = w;
    locs[k++] = lca(u, v);
    locs[k++] = lca(v, w);
    locs[k++] = lca(w, u);
    ll ans = INF;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            ans = min(ans, compute_for(u, v, locs[i], w, locs[j]));
            ans = min(ans, compute_for(u, w, locs[i], v, locs[j]));
            ans = min(ans, compute_for(v, u, locs[i], w, locs[j]));
            ans = min(ans, compute_for(v, w, locs[i], u, locs[j]));
            ans = min(ans, compute_for(w, u, locs[i], v, locs[j]));
            ans = min(ans, compute_for(w, v, locs[i], u, locs[j]));
        }
    }
    printf("%lld\n", ans);
}

int main() {
    int z;
    scanf("%d", &z);
    while (z--) solve();
}