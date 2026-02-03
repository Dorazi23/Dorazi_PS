#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define INF 4e18
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n;
vector<int> adj[100005], parent(100005, -1);

void bfs (int root) {
    queue<int> q;
    q.push(root);
    parent[root] = 0;
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        // cout << cur << endl;
        for (auto nxt : adj[cur]) {
            if (cur == nxt || parent[nxt] != -1) continue;
            parent[nxt] = cur;
            q.push(nxt);
        }
    }
}

void input () {
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(1);

    for (int i = 2; i <= n; i++) {
        cout << parent[i] << endl;
    }
}

int main() {
    fastio;
    input();
}