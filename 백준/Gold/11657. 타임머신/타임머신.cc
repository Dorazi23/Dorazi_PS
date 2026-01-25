#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000007
#define INF 4e18
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
vector<pair<ll,int>> adj[505];
ll edge[505][505];
ll dist[505];
int n, m;

void input () {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        for (int j = 1; j <= n; j++) {
            edge[i][j] = INF;
        }
    }
    
    while (m--) {
        int a, b; ll c; cin >> a >> b >> c;
        edge[a][b] = min(edge[a][b], c);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (edge[i][j] < INF) {
                adj[i].push_back({edge[i][j], j});
            }
        }
    }
    
    bool negCycle = false;
    dist[1] = 0;
    for (int edge_num = 1; edge_num <= n+1; edge_num++) {
        for (int cur = 1; cur <= n; cur++) {
            if (dist[cur] == INF) continue;
            for (auto nxt : adj[cur]) {
                if (dist[nxt.Y] > dist[cur] + nxt.X) {
                    dist[nxt.Y] = dist[cur] + nxt.X;
                    if (edge_num >= n) negCycle = true;
                }
            }
        }
    }

    if (negCycle) cout << "-1" << endl;
    else {
        for (int i = 2; i <= n; i++) {
            if (dist[i] >= INF) cout << "-1" << endl;
            else cout << dist[i] << endl;
        }
    }
}

int main() {
    fastio;
    input();
}