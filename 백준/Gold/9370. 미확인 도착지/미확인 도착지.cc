#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 4e17
using namespace std;
using ll = long long;
int target[105], edge[2005][2005];
vector<pair<ll,int>> adj[2005];
ll A[2005], B[2005], C[2005];
// A는 g에서 모든 노드까지 최단 거리
// B는 h에서 모든 노드까지 최단 거리 
// C는 시작지점에서 모든 노드까지 최단 거리

void dijkstra (int st, ll dist[]) {
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    dist[st] = 0;
    pq.push({0, st});
    while (!pq.empty()) {
        auto [D, cur] = pq.top(); pq.pop();
        if (dist[cur] != D) continue;
        for (auto [d, nxt] : adj[cur]) { // {거리, 노드}
            if (dist[nxt] <= dist[cur] + d) continue;
            dist[nxt] = dist[cur] + d;
            pq.push({dist[nxt], nxt});
        }
    }
}

void input () {
    fill(target, target+105, 0); fill(A, A+2005, INF); fill(B, B+2005, INF); fill(C, C+2005, INF);
    for (int i = 0; i < 2005; i++) fill(edge[i], edge[i]+2005, 1e9);
    for (int i = 0; i < 2005; i++) adj[i].clear();
    
    int n, m, t; cin >> n >> m >> t;
    int s, g, h; cin >> s >> g >> h;
    while (m--) {
        int u, v, d; cin >> u >> v >> d;
        adj[u].push_back({d, v});
        adj[v].push_back({d, u});
        edge[u][v] = min(edge[u][v], d);
        edge[v][u] = edge[u][v];
    }
    for (int i = 0; i < t; i++) cin >> target[i];

    dijkstra(g, A);
    dijkstra(h, B);
    dijkstra(s, C);

    vector<int> res;
    for (int i = 0; i < t; i++) {
        int tar = target[i];
        ll d = min(A[s] + edge[g][h] + B[tar], A[tar] + edge[g][h] + B[s]);
        if (d > C[tar]) continue;
        res.push_back(target[i]);
    }

    sort(res.begin(), res.end());
    for (auto x : res) cout << x << " ";
    cout << endl;
}

int main() {
    fastio;
    int t; cin >> t;
    while (t--) {
        input();
    }
}