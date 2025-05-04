#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int n, m;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int dist[105][105];
queue<pair<int,int>> q;

bool OutOfBounds(int x, int y, int n, int m){
    return x < 0 || x >= n || y < 0 || y >= m; 
}

int solution(vector<vector<int> > maps)
{
    int n = maps.size();
    int m = maps[0].size();
    int answer = 0;
    memset(dist, -1, sizeof(dist)); 
    q.push({0,0});
    dist[0][0] = 1;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(OutOfBounds(nx,ny,n,m)) continue; //범위를 넘어간 자리
            if(dist[nx][ny] != -1 || maps[nx][ny] != 1) continue; //이미 지났거나 벽이 있는 자리
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            q.push({nx,ny});
        }
    }
    answer = dist[n-1][m-1];
    return answer;
}