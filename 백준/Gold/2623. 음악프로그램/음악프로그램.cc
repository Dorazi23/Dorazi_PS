#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define INF 0x7fffffff
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n, m;
int indeg[1005];
vector<int> adj[1005];
int arr[1005];
vector<int> ans;

void input () {
    fastio;
    cin >> n >> m;
    while(m--){
        memset(arr, 0, sizeof(arr));
        int k; cin >> k;
        for (int i = 0; i < k; i++) {
            cin >> arr[i];
        }
        // 1 4 3

        for (int i = 0; i < k-1; i++) {
            int u = arr[i], v = arr[i+1];
            adj[u].push_back(v);
            indeg[v]++;
        }
    }

}

void output () {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        ans.push_back(cur);
        for (auto nxt : adj[cur]) {
            indeg[nxt]--;
            if (indeg[nxt] == 0) q.push(nxt);
        }
    }

    bool flag = 0;
    for (int i = 1; i <= n; i++) {
        if(indeg[i] != 0) {
            flag = 1;
            break;
        }
    }

    if (!flag) { 
        for (auto val : ans) {
            cout << val << endl;
        }
    }
    else {
        cout << "0" << endl;
    }
}
 
int main() {
    input();
    output();
}