#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define INF 0x3f3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int n, m, t;
int board[105][105];
int addDust[105][105];
bool prevDiffusion [105][105];
pair<int,int> up = {-100, -100};
pair<int,int> down = {-100, -100};

bool oob (int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= m;
}

void dust_diffusion () {
    memset(addDust, 0, sizeof(addDust));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) { 
            // (i, j)는 확산의 시작이 될 칸

            // 이전에 먼지가 없던 곳에는 확산이 발생하지 않음
            if (!prevDiffusion[i][j]) continue;

            // 확산될 먼지가 없는 경우 스킵
            if (board[i][j] < 5) continue; 
            
            int cnt = 0; // 확산될 칸의 개수 
            int val = (board[i][j] / 5); // 확산될 먼지의 양
            
            for (int dir = 0; dir < 4; dir++) {
                // (nx, ny)는 확산의 대상이 될 칸 
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                
                // 칸이 없거나 공기청정기면 스킵
                if (oob(nx, ny) || board[nx][ny] == -1) continue; 
                
                // 확산될 칸에 있던 먼지와 확산된 양을 합산
                addDust[nx][ny] += val;
                
                // 확산된 칸의 개수 +1
                cnt++;
            }

            // 기존 양에서 확산된 양을 뺌
            board[i][j] -= (val * cnt);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == -1) continue;
            board[i][j] += addDust[i][j];
        }
    }
}

void cleanUp () {
    pair<int,int> cur = {up.X, up.Y+1};
    int tmp = 0, val = board[cur.X][cur.Y];
    board[cur.X][cur.Y] = 0; // 공기청정기 바로 앞은 항상 0
    
    while (true) {
        //cout << cur.X << " " << cur. Y << endl;
        auto nxt = cur;
        
        
        if (cur.X == up.X) {
            if (cur.Y + 1 >= m) nxt.X--;
            else nxt.Y++;
        }
        else if (cur.X == 0) {
            if (cur.Y - 1 < 0) nxt.X++;
            else nxt.Y--;
        }
        else {
            // 위 
            if (cur.Y + 1 >= m) nxt.X--;
                
            // 아래
            else nxt.X++;
        }

        // 다음이 공기청정기면 끝
        if (nxt.X == up.X && nxt.Y == up.Y) break;
        
        tmp = board[nxt.X][nxt.Y];
        board[nxt.X][nxt.Y] = val;
        val = tmp;
        cur = nxt;
    }
}

void cleanDown () {
    pair<int,int> cur = {down.X, down.Y+1};
    int tmp = 0, val = board[cur.X][cur.Y];
    board[cur.X][cur.Y] = 0; // 공기청정기 바로 앞은 항상 0
    
    while (true) {
        // cout << cur.X << " " << cur. Y << endl;
        auto nxt = cur;
        
        if (cur.X == down.X) {
            // 아래
            if (cur.Y + 1 >= m) nxt.X++;
            // ->
            else nxt.Y++;
        }
        else if (cur.X == n-1) {
            // 위
            if (cur.Y - 1 < 0) nxt.X--;
            // <-
            else nxt.Y--;
        }
        else {
            if (cur.Y + 1 >= m) nxt.X++;
            else nxt.X--;
        }
        

        // 다음이 공기청정기면 끝
        if (nxt.X == down.X && nxt.Y == down.Y) break;
        
        tmp = board[nxt.X][nxt.Y];
        board[nxt.X][nxt.Y] = val;
        val = tmp;
        cur = nxt;
    }
}

void input () {
    cin >> n >> m >> t;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] > 0) prevDiffusion[i][j] = 1;
            if (board[i][j] == -1) {
                if (up.X == -100) up = {i, j};
                else down = {i, j};
            }
        }
    }
}

int answer;
void ans () {
    while (t--) {
        // prevDiffusion 초기화
        memset(prevDiffusion, 0, sizeof(prevDiffusion));
        
        // prevDiffusion 배열을 갱신
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] > 0) prevDiffusion[i][j] = 1;
            }
        }
        
        dust_diffusion();
        cleanUp();
        cleanDown();
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] <= 0) continue;
            answer += board[i][j];
        }
    }

    cout << answer << endl;
}

int main() {
    fastio;
    input();
    ans();
}