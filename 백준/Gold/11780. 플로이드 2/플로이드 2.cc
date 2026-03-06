#include <bits/stdc++.h>
#define endl '\n'
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
int n, m;
int d[105][105];
int nxt[105][105];
const int INF = 0x3f3f3f;

int main() {
    fastio;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        fill(d[i], d[i]+1+n, INF);
    }
    while(m--){
        int u, v, w; cin >> u >> v >> w;
        if(w < d[u][v])
            d[u][v] = w;
            nxt[u][v] = v;
    }
    for (int i = 1; i <= n; i++) 
        d[i][i] = 0;

    for (int k = 1; k <= n; k++) {
        for (int j = 1; j <= n; j++) {
            for (int i = 1; i <= n; i++) {
                if(d[i][k] + d[k][j] < d[i][j]){
                    d[i][j] = d[i][k] + d[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if(d[i][j] == INF) cout << "0 ";
            else cout << d[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if(nxt[i][j] == 0){
                cout << "0" << endl; 
                continue;
            }
            int idx= nxt[i][j];
            vector<int> track;
            track.push_back(i);
            track.push_back(idx);
            while(1){
                if(idx == j){
                    break;
                }
                idx = nxt[idx][j];
                track.push_back(idx);
            }
            cout << track.size() << " ";
            for (auto i : track) {
                cout << i << " ";
            }
            cout << endl;
        }
    }
}