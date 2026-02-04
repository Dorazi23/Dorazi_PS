#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
int n, m;
vector<pair<int,int>> adj[1005];
bool vis[1005];

void bfs (int st, int en) {
    memset(vis, 0, sizeof(vis));
    queue<pair<int,int>> q;
    q.push({st, 0});
    vis[st] = 1;
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        if (cur.X == en) {
            cout << cur.Y << endl;
            return;
        }
        
        for (auto nxt : adj[cur.X]) {
            if (vis[nxt.X]) continue;
            vis[nxt.X] = 1;
            q.push({nxt.X, cur.Y + nxt.Y});
        }
    }
}

void input () {
    cin >> n >> m;
    for (int i = 0; i < n-1; i++) {
        int u, v, d; cin >> u >> v >> d;
        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }
    
    while(m--) {
        int st, en; cin >> st >> en;
        bfs (st, en);
    }
}

int main() {
    fastio;
    input();
}