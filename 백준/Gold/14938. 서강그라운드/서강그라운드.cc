#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define INF 0x3f3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n, m, r;
int farm[105];
int d[105][105];

int main() {
    fill(&d[0][0], &d[105][105], INF);
    fastio;
    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++) cin >> farm[i];
    for (int i = 0; i < r; i++) {
        int u, v, w; cin >> u >> v >> w;
        d[u][v] = min(d[u][v], w);
        d[v][u] = min(d[v][u], w);
    }
    for (int i = 1; i <= n; i++) d[i][i] = 0;
    
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }
    int ans = 0;
    for (int k = 1; k <= n; k++) { //수색 시작지점
        int val = 0;
        for (int i = 1; i <= n; i++) { //수색 범위 
            if(d[k][i] <= m){
                val += farm[i];
            }
        }
        ans = max(ans, val);
    }
    cout << ans << endl;
}