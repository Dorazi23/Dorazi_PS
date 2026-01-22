#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000007
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
const long long INF = 4e18;
bool visible[100005];
vector<pair<int,int>> adj[100005];
int n, m;
ll res = INF;
ll dist[100005];

void dijkstra (int st, int en) {
    priority_queue< pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>> > pq;
    dist[st] = 0;
    pq.push({dist[st], st});
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (dist[cur.Y] != cur.X) continue;
        for (auto nxt : adj[cur.Y]) {
            if (dist[nxt.Y] <= dist[cur.Y] + nxt.X) continue;
            dist[nxt.Y] = dist[cur.Y] + nxt.X;
            pq.push({dist[nxt.Y], nxt.Y});
        }
    }
    res = dist[en];
    return;
}

void input () {
    fill(dist, dist+100005, INF);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> visible[i];
    while (m--) {
        int a, b, t; cin >> a >> b >> t;
        if (a != n-1 && visible[a]) continue;
        if (b != n-1 && visible[b]) continue;
        adj[a].push_back({t, b});
        adj[b].push_back({t, a});
    }
    dijkstra (0, n-1);
    
    if (res == INF) cout << "-1" << endl;
    else cout << res << endl;
}

int main() {
    input();
}