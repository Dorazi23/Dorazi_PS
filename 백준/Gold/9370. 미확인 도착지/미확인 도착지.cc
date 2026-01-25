#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000007
#define INF 4e18
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int s, g, h; 
vector<pair<ll, int>> adj[2005];

void dijkstra (int st, int en, ll dist[2005]) {
    priority_queue< pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>> > pq;
    dist[st] = 0;
    pq.push({dist[st], st}); // 거리, 노드 
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop(); // X: 거리, Y: 노드
        if (cur.X != dist[cur.Y]) continue;
        
        for (auto nxt : adj[cur.Y]) {
            if (dist[nxt.Y] > dist[cur.Y] + nxt.X) {
                dist[nxt.Y] = dist[cur.Y] + nxt.X;
                pq.push({dist[nxt.Y], nxt.Y});
            }
        }
    }
}

void input () {
    ll edge = INF; // g-h 간선만 저장할 용
    int n, m, t; cin >> n >> m >> t; // 교차로 도로 목적지 
    cin >> s >> g >> h; // 시작지점 냄새맡은 구간 [g][h] (g != h)
    for (int i = 0; i <= n+1; i++) adj[i].clear();
    vector<int> target;
    
    while (m--) {
        int a, b; ll d; cin >> a >> b >> d;
        adj[a].push_back({d, b});
        adj[b].push_back({d, a});
        if ((a == g && b == h) || (a == h && b == g)) {
            edge = min(edge, d);
        }
    }

    while (t--) {
        int num; cin >> num; 
        target.push_back(num);
    }
    sort(target.begin(), target.end());

    ll S[2005], G[2005], H[2005];
    for (auto en : target) {
        fill (S, S+n+1, INF); fill (G, G+n+1, INF); fill (H, H+n+1, INF);
        dijkstra(s, en, S);
        dijkstra(g, en, G);
        dijkstra(h, en, H);
        if ((S[en] == S[g] + edge + H[en]) || (S[en] == S[h] + edge + G[en])) cout << en << " ";
    }
    cout << endl;
}

int main() {
    fastio;
    int T; cin >> T;
    while (T--) {
        input();
    }
}