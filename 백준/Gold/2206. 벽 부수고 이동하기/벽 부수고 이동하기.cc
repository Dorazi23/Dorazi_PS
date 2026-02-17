#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>
using namespace std;

#define X first
#define Y second

int n, m;
string board[1004];
int dist1[1004][1004];
int dist2[1004][1004];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
bool IsOutOfBounds(int x, int y) {
	return x < 0 || x >= n || y < 0 || y >= m;
}

queue<pair<int,int>> Q;

int main() {
   
    cin >> n >> m;
    for (int i = 0; i < n; i++) { //board 구성
        cin >> board[i];
    }
    
    for (int i = 0; i < n; i++) { //dist1, dist2 구성
        for (int j = 0; j < m; j++) {
            dist1[i][j] = dist2[i][j] = -1;
        }
    }
    //출발점 설정
    dist1[0][0] = 1;
    dist2[n-1][m-1] = 1;

    //bfs
    Q.push({0,0}); 
    while(!Q.empty()){
        pair<int,int> cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] == '1' || dist1[nx][ny] != -1) continue;
            dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
            Q.push({nx,ny});
        }
    }

    Q.push({n-1,m-1});
    while(!Q.empty()){
        pair<int,int> cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] == '1' || dist2[nx][ny] != -1) continue;
            dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
            Q.push({nx,ny});
        }
    }

    int min_dist = 0x7fffff;
    if(dist2[0][0] >= 0) min_dist = dist2[0][0]; //벽이 없으면 존재할 최단거리 저장
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(board[i][j] == '0') continue; //벽이 아닌 곳 제외
            int min_dist1 = 0x7fffff;
            int min_dist2 = 0x7fffff;
            for (int dir = 0; dir < 4; dir++) {
                int x = i + dx[dir];
                int y = j + dy[dir];
                if(IsOutOfBounds(x,y)) continue; //범위를 벗어나지 않고
                if(dist1[x][y] >= 0) min_dist1 = min(min_dist1, dist1[x][y]); //벽 근처에 이동 거리 발견
                if(dist2[x][y] >= 0) min_dist2 = min(min_dist2, dist2[x][y]);
            }
            min_dist = min(min_dist, min_dist1+min_dist2+1);
        }
    }

    if(min_dist == 0x7fffff) cout<<"-1";
    else cout<<min_dist;
}