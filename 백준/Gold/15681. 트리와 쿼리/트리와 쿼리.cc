#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000007
#define INF 0x3f3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ull = unsigned long long;
int n, r, q;
vector<int> adj[100005];
vector<int> p(100005, -1);
vector<int> dp(100005, 1);

void func (int cur) {
    dp[cur] = 1;
    for (auto nxt : adj[cur]) {
        if (nxt == p[cur]) continue;
        p[nxt] = cur;
        func(nxt);
        dp[cur] += dp[nxt];
    }
}

void input () {
    cin >> n >> r >> q;    
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        if (u == r) p[v] = u;
    }
    
    func(r);

    while (q--) {
        int num; cin >> num;
        cout << dp[num] << endl;
    }
    
} 

int main() {
    fastio; 
    input();
}