#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000007
#define INF 0x3f3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int edge[505][505];
int dist[505]; // 시작점에서 떨어진 거리 

void input () {
    int n, m, w; cin >> n >> m >> w;

    for (int i = 1; i <= n; i++) {
        dist[i] = MAX;
        for (int j = 1; j <= n; j++) {
            edge[i][j] = MAX;
        }
    }
    
    while (m--) { // 길
        int s, e, t; cin >> s >> e >> t;
        edge[s][e] = min(edge[s][e], t);
        edge[e][s] = min(edge[e][s], t);
    }
    
    while (w--) { // 웜홀 
        int s, e, t; cin >> s >> e >> t;
        edge[s][e] = min(edge[s][e], -t);
    }

    vector<pair<int,int>> adj[505]; // 노드, 거리
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (edge[i][j] < MAX) {
                adj[i].push_back({j, edge[i][j]});
            }
        }
    }
    
    bool negCycle = false; // 음의 사이클 존재 여부 
    dist[1] = 0; // 시작점 
    for (int edge_num = 1; edge_num <= n+1; edge_num++) {
        for (int cur = 1; cur <= n; cur++) {
            for (auto nxt : adj[cur]) {
                if (dist[nxt.X] > dist[cur] + nxt.Y) {
                    dist[nxt.X] = dist[cur] + nxt.Y;
                    if (edge_num >= n) negCycle = true;
                }
            }
        }
    }

    if (negCycle) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    fastio;
    int t; cin >> t;
    while (t--) {
        input();
    }
}