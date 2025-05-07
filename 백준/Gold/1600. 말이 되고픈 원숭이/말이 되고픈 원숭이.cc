#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; i++)
#define X first
#define Y second
const int INF = 0x7f7f7f7f;

int k, n, m;
int board[500][500];
int dist[500][500][31];

int kdx[] = {-1,-2,-2,-1,1,2,2,1};
int kdy[] = {-2,-1,1,2,2,1,-1,-2};

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

queue<pair<pair<int,int>,int>> Q;


int main() {
    cin >> k;
    cin >> m >> n;
    for (int i = 0; i < n; i++) { //board 구성
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) { //dist 구성
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 31; k++) {
                dist[i][j][k] = -1;
            }
        }
    }
    dist[0][0][0] = 0; //출발점 설정

    Q.push({{0,0},0});
    while(!Q.empty()){
        pair<pair<int,int>,int> cur = Q.front(); Q.pop();
        int x = cur.X.X;
        int y = cur.X.Y;
        int cnt = cur.Y;
        if(cnt < k){
            for (int dir = 0; dir < 8; dir++) {
                int nx = x + kdx[dir];
                int ny = y + kdy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(board[nx][ny] != 0 || dist[nx][ny][cnt+1] > -1) continue;
                dist[nx][ny][cnt+1] = dist[x][y][cnt] + 1;
                //cout << dist[nx][ny][cnt+1] << endl;
                Q.push({{nx,ny},cnt+1});
            }
        }
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] != 0 || dist[nx][ny][cnt] > -1) continue;
            dist[nx][ny][cnt] = dist[x][y][cnt] + 1;
            Q.push({{nx,ny},cnt});
        }
    }
    int mn = INF;
    rep(i,0,k+1){
        if(dist[n-1][m-1][i]==-1) continue;
        mn = min(mn,dist[n-1][m-1][i]);
    }
    if(mn==INF) mn =-1;
    cout << mn;
}