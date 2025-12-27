#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define INF 0x3f3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;


vector<pair<int,int>> dir = {
{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int board[100][100];
bool washed[100][100];
int n, m, answer;

//   0
// 3   1  
//   2
//

int backstep(int d) {
    if (d == 0) return 2;
    else if (d == 1) return 3;
    else if (d == 2) return 0;
    else return 1;
}

int spin(int d) {
    if (d-1 < 0) return 3;
    return d-1;
}

// false: 모두 청소가 됨
bool check (int x, int y) { // 현재 칸을 중심으로 청소 여부 체크
    for (auto [dx, dy] : dir) {
        int nx = x + dx;
        int ny = y + dy;
        
        // 벽이 아니면서 청소가 안된 부분을 찾음
        if (!washed[nx][ny] && board[nx][ny] != 1) {
            return true;
        }
    }
    return false;
}

void ans(int x, int y, int d) {

    pair<int,int> cur = {x, y};
    while(true) {
  
        if (!washed[cur.X][cur.Y] && board[cur.X][cur.Y] != 1) { // 현재 위치를 청소 
            answer++;
            washed[cur.X][cur.Y] = 1;
        }

        if(check(cur.X, cur.Y)) { // 청소 안된 부분이 존재 
            int cnt = 4;
            while(cnt--) {
                d = spin(d);
                int nx = cur.X + dir[d].X;
                int ny = cur.Y + dir[d].Y;
                // 벽이거나 이미 청소한 곳이면 넘기기
                if (board[nx][ny] == 1 || washed[nx][ny]) continue;
                cur = {nx, ny};
                break;
            }
        }
            
        else { // 4면 모두 청소됨
            int back = backstep(d); // 뒤로 갈 방향
            int nx = cur.X + dir[back].X;
            int ny = cur.Y + dir[back].Y;

            if (board[nx][ny] == 1) break;
            else cur = {nx, ny};
            
            // // 벽이 아니고, 방문 (큐에 없는 곳) 하지 않았다면
            // if (board[nx][ny] != 1) {
            //     cur = {nx, ny};
            //     continue;
            // }
        }
    }

    cout << answer << endl;
}

int main() {
    fastio; cin >> n >> m;
    int x, y, d; cin >> x >> y >> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    ans(x, y, d);

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << washed[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}