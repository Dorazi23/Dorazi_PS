#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
bool vis[1000];
int flag = 0;
vector<int> adj[1000];
void dfs(int cur, int before){
    for (auto nxt : adj[cur]) {
        if(nxt == before) continue;
        if(nxt != before && vis[nxt]){
            flag = 1;
            return;
        }
        vis[nxt] = 1;
        dfs(nxt, cur);
    }
}

int main() {
    fastio;
    int c = 1;
    while(1){
        memset(vis, 0, sizeof(vis)); 
        int ans = 0;
        int n, m; cin >> n >> m;
        if(n == 0 && m == 0){ //exit
            return 0;
        }

        while(m--){
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i = 1; i <= n; i++) {
            flag = 0;
            if(vis[i]) continue;
            dfs(i, -1);
            if(!flag){
                ans++;
            }
        }
        if(ans > 1){
            cout << "Case " << c << ": " << "A forest of " << ans << " trees." << endl;
        }
        else if(ans == 1){
            cout << "Case " << c << ": " << "There is one tree." << endl;
        }
        else{
            cout << "Case " << c << ": " << "No trees." << endl;
        }

        for (int i = 1; i <= n; i++) { //reset
            adj[i].clear();
        }
        c++;
    }
}