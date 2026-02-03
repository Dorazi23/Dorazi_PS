#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
vector<pair<int,int>> adj[1005];
int d[1005];
const int INF = 0x3f3f3f;
int res;
void dijkstra(int val, int tar){
    memset(d, INF, sizeof(d));
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    d[val] = 0; pq.push({d[val], val});
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if(d[cur.Y] != cur.X) continue;
        if(cur.Y == tar){
            res = d[cur.Y];
            return;
        } 
        for (auto nxt : adj[cur.Y]) {
            if(d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({d[nxt.Y], nxt.Y});
        }
    }
}

int main() {
    int n, m, depth = 0; cin >> n >> m;
    for (int i = 0; i < n-1; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    while(m--){
        int a, b; cin >> a >> b;
        dijkstra(a, b);
        cout << res << endl;        
    }
}
