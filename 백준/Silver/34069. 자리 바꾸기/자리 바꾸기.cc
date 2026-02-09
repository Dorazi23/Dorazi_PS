#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define fastio cin.tie(0)->sync_with_stdio(0)
#define MAX 1000000000
#define INF 4e18
using namespace std;
using ll = long long;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, m, board[505][505];
bool vis[505][505];

bool oob (int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= m;
}

void input () {
    cin >> n >> m;
    if (n % 2 != 0 && m % 2 != 0) { // 모두 홀수면 불가능
        cout << "No" << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    int val = n*m/2;

    auto bfs = [&] (int x, int y) -> void {
        queue<pair<int,int>> q;
        q.push({x, y});
        int cnt = 0;
        
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                
                // 맵 밖이거나 이미 자리를 바꿨으면 넘김 
                if (oob(nx,ny) || vis[nx][ny] || vis[x][y]) continue;
                
                vis[x][y] = vis[nx][ny] = 1;
                swap(board[nx][ny], board[x][y]);
                cnt++;
                q.push({nx, ny});
            }
        }
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bfs(i, j);
        }
    }

    cout << "Yes" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    fastio;
    input();
}