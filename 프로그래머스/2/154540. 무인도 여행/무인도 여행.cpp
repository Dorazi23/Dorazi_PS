#include <bits/stdc++.h>

using namespace std;
int n, m; //maps의 크기 
int days; //생존일수
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
bool vis[105][105];

bool OutOfBounds(int x, int y){
    return x < 0 || x >= n || y < 0 || y >= m;
}

void dfs(int x, int y, const vector<string> maps){
    if(vis[x][y]) return;
    vis[x][y] = 1;
    for(int dir = 0; dir < 4; dir++){
        int nx = x + dx[dir]; 
        int ny = y + dy[dir];
        if(OutOfBounds(nx, ny) || vis[nx][ny]) continue; //범위를 벗어났거나 이미 지났던 곳이면 스킵
        if(maps[nx][ny] == 'X') continue; //섬이 아니라면 스킵 
        days += (maps[nx][ny] - '0');
        dfs(nx, ny, maps);
    }
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    n = maps.size();
    m = maps[0].size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(maps[i][j] != 'X' && !vis[i][j]){
                days = maps[i][j] - '0';
                dfs(i, j, maps);   
            }
            if(days != 0) answer.push_back(days);
            days = 0;
        }
    }
    if(answer.empty()) answer.push_back(-1);
    else sort(answer.begin(), answer.end());
    return answer;
}