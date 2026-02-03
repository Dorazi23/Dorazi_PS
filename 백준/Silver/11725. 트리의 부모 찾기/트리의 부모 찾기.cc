#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
vector<int> adj[100005];
int p[100005];
int n;

void dfs(int cur){
    for (auto nxt : adj[cur]) {
        if(p[cur] == nxt) continue;
        p[nxt] = cur;
        dfs(nxt);
    }
}

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n; int t = n;
    while(t--){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
    dfs(1);
    for (int i = 2; i <= n; i++) {
        cout << p[i] << endl;   
    }
}