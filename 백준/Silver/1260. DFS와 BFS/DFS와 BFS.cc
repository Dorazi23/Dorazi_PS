#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1005];
bool vis[1005];

void bfs(int n, int tar){ //정점의 개수, 탐색 시작점
        queue<int> Q;
        Q.push(tar);
        vis[tar] = 1;
        cout << tar << " ";
        while(!Q.empty()){
            int cur = Q.front(); Q.pop();
            for (auto nxt : adj[cur]) {
                if(vis[nxt]) continue;
                Q.push(nxt);
                vis[nxt] = 1;
                cout << nxt << " ";
            }
        }
}
    

void dfs(int cur){
    vis[cur] = 1;
    for (auto nxt : adj[cur]) {
        if(vis[nxt]) continue;
        cout << nxt << " ";
        dfs(nxt);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, o;
    cin >> n >> m >> o;  
        
    while(m--){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);  
        adj[v].push_back(u); 
    }
    
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(),adj[i].end());
    }
    cout << o << " ";
    dfs(o);
    for (int i = 0; i < 1005; i++) {
        vis[i] = 0;
    }
    cout << '\n';
    bfs(n, o);
    
}