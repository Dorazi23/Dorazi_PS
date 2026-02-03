#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
int n, r, q;
vector<int> adj[100005], p(100005, -1);
int sz[100005];

int dfs (int cur) {
    for (auto nxt : adj[cur]) {
        if (p[cur] == nxt) continue;
        p[nxt] = cur; 
        sz[cur] += dfs(nxt);
    }

    return sz[cur];
}

void input () {
    fill (sz, sz+100004, 1);
    cin >> n >> r >> q;
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(r); // 부모 배열 채우기
    
    while (q--) {
        int m; cin >> m;
        cout << sz[m] << endl;
    }
}

int main() {
    fastio;
    input();
}