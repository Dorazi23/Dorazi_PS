#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define INF 0x3f3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n, k, cnt;
int dist[100005];
int mn = -1;

bool oob (int x) {
    return x < 0 || x > 100000;
}

void input () {
    memset(dist, -1, sizeof(dist));
    cin >> n >> k;

    queue<int> q;
    dist[n] = 0;
    q.push(n);

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        if (mn != -1 && dist[cur] > mn) continue;

        if (cur == k) {
            if (mn == -1) mn = dist[cur];
            if (mn == dist[cur]) cnt++;
        }

        for (auto nxt : {cur-1, cur+1, 2*cur}) {
            if (oob(nxt)) continue;

            if (dist[nxt] == -1 || dist[nxt] == dist[cur] + 1) {
                dist[nxt] = dist[cur] + 1;
                q.push(nxt);
            }
        }
    }

    cout << dist[k] << endl << cnt << endl;
}

int main() {
    fastio;
    input();
}