#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define X first
#define Y second
#define INF 0x4f4f4f4f
using namespace std;
int n, m, answer = INF, board[105][105];
bool chk[105][105];
deque<pair<int,int>> dq;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

bool oob (int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= n;
}

int bfs (vector<pair<int,int>>& v) {
    int dist[105][105];
    memset(dist, -1, sizeof(dist));
    queue<pair<int,int>> q;

    for (auto [sx, sy] : v) {
        q.push({sx, sy});
        dist[sx][sy] = 0;
    }

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (oob(nx, ny) || board[nx][ny] == 1 || dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }

    int mx = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == -1 && board[i][j] != 1) return -1;
            mx = max(mx, dist[i][j]);
        }
    }

    return mx;
}

void input () {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) dq.push_back({i, j});
        }
    }

    vector<int> temp;
    for (int i = 0; i < dq.size(); i++) {
        if (i < m) temp.push_back(1);
        else temp.push_back(0);
    }

    do {
        vector<pair<int,int>> v;
        for (int i = 0; i < dq.size(); i++) {
            if (temp[i]) v.push_back(dq[i]);
        }
        int res = bfs(v);
        if (res == -1) continue;
        else answer = min(answer, res);
    } while (prev_permutation(temp.begin(), temp.end()));
    
    if (answer == INF) cout << "-1" << endl;
    else cout << answer << endl;
}

int main() {
    fastio;
    input();
}