#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 10005
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
int n, diam;
vector<pair<int,int>> adj[MAX];

int dfs(int cur){
    int first = 0, second = 0;
    for (auto nxt : adj[cur]) {
        int dist = dfs(nxt.X) + nxt.Y;
        if(dist > first){
            second = first;
            first = dist;
        }
        else if(dist > second){
            second = dist;
        }
        diam = max(diam, first + second);
    }
    return first;
}

int main() {
    fastio;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }
    dfs(1);
    cout << diam << endl;
}