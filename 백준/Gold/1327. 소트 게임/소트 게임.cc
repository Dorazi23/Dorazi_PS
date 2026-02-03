#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 0x3f3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
int n, k;
vector<int> tar, v;
set<vector<int>> vis;

void input () {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) tar.push_back(i);
    for (int i = 0; i < n; i++) {
        int m; cin >> m;
        v.push_back(m);
    }

    queue<pair<vector<int>, int>> q;
    vis.insert(v);
    q.push({v, 0});
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        
        if (cur.X == tar) {
            cout << cur.Y << endl;
            return;
        }

        for (int i = 0; i <= n-k; i++) {
            vector<int> temp(cur.X);
            reverse(temp.begin()+i, temp.begin()+i+k);
            if (vis.find(temp) != vis.end()) continue;
            else {
                vis.insert(temp);
                q.push({temp, cur.Y+1});
            }
        }
    }

    cout << "-1" << endl;
}

int main() {
    fastio;
    input();
}