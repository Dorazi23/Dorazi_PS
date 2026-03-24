#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 0x4f4f4f4f
using namespace std;
using ll = long long;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, m, k;
int dist[1005][1005][15][3];
string board[1005];

bool oob (int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= m;
}

void bfs () {
    // 초기화
    for (int i = 0; i < 1005; i++) {
        for (int j = 0; j < 1005; j++) {
            for (int k = 0; k < 15; k++) {
                fill (dist[i][j][k], dist[i][j][k]+3, -1);
            }
        }
    }
    
    // 낮은 0, 밤은 1
    queue<tuple<int,int,int,bool>> q;
    q.push({0, 0, 0, 0});
    dist[0][0][0][0] = 1;
    
    while (!q.empty()) {
        auto [x, y, count, day] = q.front(); q.pop();

        if (x == n-1 && y == m-1) {
            cout << dist[x][y][count][day] << endl;
            return;
        }
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (oob(nx, ny)) continue; // 맵 밖이면 넘김 
            if (board[nx][ny] == '0') { // 이동 가능
                if (dist[nx][ny][count][!day] != -1) continue;
                dist[nx][ny][count][!day] = dist[x][y][count][day] + 1;
                q.push({nx, ny, count, !day});
            }
            // 다음이 벽이고, 부술 수 있을 때 
            if (board[nx][ny] == '1' && count < k) {
                if (!day) { // 현재 낮일 때 
                    if (dist[nx][ny][count+1][1] != -1) continue;
                    dist[nx][ny][count+1][1] = dist[x][y][count][0] + 1;
                    q.push({nx, ny, count+1, 1});    
                }
                else { // 현재 밤
                    dist[x][y][count][!day] = dist[x][y][count][day] + 1;
                    q.push({x, y, count, !day});
                }
            }
        }
    }

    cout << -1 << endl;
}

void input () {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> board[i];
    bfs();
}

int main() {
    fastio;
    input();
}