#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 100000
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int t, n, m;
int vis[1005][1005];
int fire[1005][1005];

bool OutOfBounds(int x, int y){
    if(x >= n || x < 0 || y >= m || y < 0) return true;
    else return false;
}

int main() {
    fastio;
    cin >> t;
    while(t--){
        memset(vis, -1, sizeof(vis));
        memset(fire, -1, sizeof(vis));
        fastio;
        cin >> m >> n;
        string board[1005]; for (int i = 0; i < n; i++) cin >> board[i];
        queue<pair<int,int>> q; //사람 이동
        queue<pair<int,int>> fq; //불 이동 
        
        //시작점 찾기
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(board[i][j] == '@'){
                    vis[i][j] = 0;
                    q.push({i,j});
                }
                if(board[i][j] == '*'){
                    fire[i][j] = 0;
                    fq.push({i,j});
                }
            }
        }
        //불의 이동
        while(!fq.empty()){
            auto [x,y] = fq.front(); fq.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if(OutOfBounds(nx,ny) || board[nx][ny] == '#' || fire[nx][ny] != -1) continue;
                fire[nx][ny] = fire[x][y] + 1;
                fq.push({nx,ny});
            }
        }
        int flag = 0;
        //사람의 이동
        while(!q.empty() && !flag){
            auto [x,y] = q.front(); q.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if(OutOfBounds(nx,ny)){ //탈출 성공
                    cout << vis[x][y] + 1 << endl;
                    flag = 1;
                    break;
                }
                //이미 지났거나, 벽이거나, 불이 붙으면 못감
                if(vis[nx][ny] != -1 || board[nx][ny] == '#') continue;
                if(fire[nx][ny] != -1 && vis[x][y] + 1 >= fire[nx][ny]) continue;
                vis[nx][ny] = vis[x][y] + 1; //이동
                q.push({nx,ny});
            }
        }
        if(!flag) cout << "IMPOSSIBLE" << endl;
    }
}