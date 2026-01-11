#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 100005
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
int n, r, q;
vector<int> adj[MAX];
int p[MAX];
int sz[MAX];

void dfs(int cur){
    sz[cur] = 1;
    for (auto nxt : adj[cur]) {
        if(p[cur] == nxt) continue;
        p[nxt] = cur;
        dfs(nxt);
        sz[cur] += sz[nxt];
    }
}

int main() {
    fastio;
    memset(p, -1, sizeof(p));
    memset(sz, 0, sizeof(sz));
    cin >> n >> r >> q;
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        if(u == r){
            p[v] = u;
        }
    }
    dfs(r); //부모 채우기
    while(q--){
        int qr; cin >> qr;
        cout << sz[qr] << endl;
    }
}