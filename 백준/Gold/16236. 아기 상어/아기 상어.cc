#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define X first
#define Y second
using namespace std;
int n, sz = 2, board[105][105];

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int x, y;

bool oob (int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= n;
}

// 현 위치로부터 도달 가능한 곳에 먹을 수 있는 물고기가 있는지 체크
tuple<int,int,int> bfs (int x, int y) { 
    // 도달 가능하며 먹을 수 있는 물고기 위치
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
    int dist[30][30]; memset(dist, -1, sizeof(dist));
    queue<pair<int,int>> q;
    dist[x][y] = 0;
    q.push({x, y});

    while (!q.empty()) {
        auto [curX, curY] = q.front(); q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            // 맵 밖을 나갔거나, 이미 방문했거나, 물고기의 크기가 상어보다 크면 넘김 
            if (oob(nx, ny) || dist[nx][ny] != -1 || board[nx][ny] > sz) continue;
            
            dist[nx][ny] = dist[curX][curY] + 1;

            // 물고기가 존재하고, 상어보다 작을 때 
            if (board[nx][ny] != 0 && sz > board[nx][ny]) {
                pq.push({dist[nx][ny], nx, ny});
            }
            q.push({nx, ny});
        }
    }

    tuple<int,int,int> p = {-1, -1, -1};
    // 먹을 수 있는 물고기가 존재하지 않음 
    if (pq.empty()) return p; 
    else {
        auto [d, x, y] = pq.top();
        auto& [td, tx, ty] = p;
        td = d, tx = x, ty = y;
        return p;
    }
}

void input () {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 9) {
                board[i][j] = 0;
                x = i, y = j;
            }
        }
    }

    int cnt = 0, t = 0;
    while (true) {
        // cout << x << " " << y << " " << t << endl;
        tuple<int,int,int> p = bfs(x, y);
        auto [td, tx, ty] = p;

        // 물고기가 존재하지 않을 때
        if (td == -1 && tx == -1 && ty == -1) { 
            cout << t << endl;
            return;
        }

        // 1. 물고기 먹고 좌표 갱신
        board[tx][ty] = 0; 
        cnt++;
        x = tx, y = ty;
        
        // 2. 크기 확인        
        if (cnt == sz) {
            sz++;
            cnt = 0;
        }

        // 3. 시간 증가 
        t += td;
    }
}

int main() {
    fastio;
    input();
}