#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 4e17
using namespace std;
using ll = long long;
int target[105];
vector<pair<ll,int>> adj[2005];
ll dist[2005];

void dijkstra (int st) {
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
    fill(target, target+105, 0); fill(dist, dist+2005, INF);
    for (int i = 0; i < 2005; i++) adj[i].clear();
    
    int n, m, t; cin >> n >> m >> t;
    int s, g, h; cin >> s >> g >> h;
    while (m--) {
        int u, v, d; cin >> u >> v >> d;
        if (u == g && v == h || u == h && v == g) { // 특정 간선이면 홀수
            adj[u].push_back({2*d-1, v});
            adj[v].push_back({2*d-1, u});
            continue;
        }
        // 특정 간선이 아니면 짝수
        adj[u].push_back({2*d, v});
        adj[v].push_back({2*d, u});
    }
    for (int i = 0; i < t; i++) cin >> target[i];

    dijkstra(s);
    vector<int> res;
    for (int i = 0; i < t; i++) {
        // 시작점부터 목적지까지 최단 거리가 홀수면 특정 간선을 지난 것
        int tar = target[i];
        if (dist[tar] & 1) res.push_back(tar);
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