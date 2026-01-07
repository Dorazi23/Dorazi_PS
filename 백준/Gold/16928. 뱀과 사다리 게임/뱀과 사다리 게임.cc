#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define INF 0x3f3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n, m;
int dist[105];
unordered_map<int,int> ladder;
unordered_map<int,int> snake;

void input () {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int u, v; cin >> u >> v;
        ladder[u] = v;
    }
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        snake[u] = v;
    }
}

bool vis[1000];
void ans () {
    memset(dist, -1, sizeof(dist));
    queue<int> q; 
    q.push(1);
    dist[1] = 0;
    
    while (!q.empty()) {
        auto cur = q.front(); q.pop();

        if (cur == 100) {
            cout << dist[cur] << endl;
            return;
        }
        
        for (int dir = 1; dir < 7; dir++) {
            int nxt = cur + dir;

            if (nxt > 100) continue;
            
            // ladder인지 확인 
            if (ladder.find(nxt) != ladder.end()) nxt = ladder[nxt];
                
            // snake인지 확인
            if (snake.find(nxt) != snake.end()) nxt = snake[nxt];
            
            if (dist[nxt] == -1) {
                dist[nxt] = dist[cur] + 1;
                q.push(nxt);
            }
        }
    }
}

int main() {
    fastio;
    input();
    ans();
}