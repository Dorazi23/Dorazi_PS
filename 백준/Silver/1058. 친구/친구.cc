#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define fastio cin.tie(0)->sync_with_stdio(0)
#define MAX 1000005
#define INF 4e18
using namespace std;
using ll = long long;
int n, cnt, ans;
bool vis[105];
vector<int> adj[105];

void input () {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char ch; cin >> ch;
            if (ch == 'N') continue;
            else {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    auto ret = [&] (int st) {
        memset(vis, 0, sizeof(vis));
        vis[st] = 1;
        cnt = 0;
        
        queue<pair<int,int>> q;
        q.push({st, 0});
        while (!q.empty()) {
            auto cur = q.front(); q.pop(); // {노드, 거리}
            for (auto nxt : adj[cur.X]) {
                if (vis[nxt] || cur.Y+1 >= 3) continue;
                vis[nxt] = 1;
                cnt++;
                q.push({nxt, cur.Y+1});
            }
        }
    };

    for (int i = 1; i <= n; i++) {
        ret(i);
        ans = max(ans, cnt);
    }

    cout << ans << endl;
}

int main() {
    fastio;
    input();
}