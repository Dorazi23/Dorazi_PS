#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 0x4f4f4f4f
using namespace std;
using ll = long long;
int n, m, k, answer;
deque<tuple<int,int,int,int,int>> dq;
// 좌표, 질량, 속도, 방향 
vector<tuple<int,int,int>> board[105][105];
int dx[] = {-1, -1, 0, 1, 1, 1,  0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

void move () {
    deque<tuple<int,int,int,int,int>> temp;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (board[i][j].empty()) continue;
            for (auto [m, s, d] : board[i][j]) {
                int nx = i + (s % n) * dx[d];
                int ny = j + (s % n) * dy[d];
                nx = ((nx-1+n) % n) + 1;
                ny = ((ny-1+n) % n) + 1;
                temp.push_back({nx, ny, m, s, d});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) board[i][j].clear();
    }
    
    for (auto [x, y, m, s, d] : temp) {
        board[x][y].push_back({m, s, d});
    }
}

void mergeAndsplit () {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (board[i][j].size() <= 1) continue;
            int sz = board[i][j].size();
            int mass = 0, speed = 0;
            int even = 0, odd = 0;
            for (auto [m, s, d] : board[i][j]) {
                mass += m;
                speed += s;
                if (d & 1) odd++;
                else even++;
            }

            board[i][j].clear(); 
            if (mass / 5 > 0) {
                if (even == 0 || odd == 0) {
                    board[i][j].push_back({mass/5, speed/sz, 0});
                    board[i][j].push_back({mass/5, speed/sz, 2});
                    board[i][j].push_back({mass/5, speed/sz, 4});
                    board[i][j].push_back({mass/5, speed/sz, 6});
                }
                else {
                    board[i][j].push_back({mass/5, speed/sz, 1});
                    board[i][j].push_back({mass/5, speed/sz, 3});
                    board[i][j].push_back({mass/5, speed/sz, 5});
                    board[i][j].push_back({mass/5, speed/sz, 7});
                }
            }
        }
    }
}

void input () {
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int x, y, M, s, d; cin >> x >> y >> M >> s >> d;
        board[x][y].push_back({M, s, d});
    }

    while (k--) {
        move();
        mergeAndsplit();
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (board[i][j].empty()) continue;
            for (auto [m, s, d] : board[i][j]) answer += m;
        }
    }
    cout << answer << endl;
}

int main() {
    fastio;
    input();
}

/*
남아있는 파이어볼의 질량의 합
 
무한 보드: 1번이 N번과 연결되어있음 
방향 : 8가지 

연산
파이어볼이 이동
같은 칸에 있는 파이어볼은 하나로 합쳐짐
각 파이어볼은 4개로 나눠짐 

나눠진 파이어볼의 질량 = 합쳐진 볼 질량/5 + 0.5
나눠진 파이어볼의 속도 = 합쳐진 볼 속도/합쳐진 파이어볼 개수 
방향은 합쳐진 볼 방향이 모두 홀수/짝수면 0, 2, 4, 6

질량이 0이면 소멸 

*/