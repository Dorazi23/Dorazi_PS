#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define fastio cin.tie(0)->sync_with_stdio(0)
#define MAX 0x3f3f3f3f
#define INF 4e18
using namespace std;
using ll = long long;
int n, tot, answer = MAX, population[105];
vector<int> adj[105];
bool vis[15], chk[15];

bool check () { // 방문하지 않은 곳들이 하나로 연결되어 있는지 확인 
    queue<int> q;

    // vis[i] 선거구의 연결성 확인
    fill (chk, chk+15, 0);
    // vis[i]인 지역 i 찾기
    for (int i = 0; i < n; i++) {
        if (!vis[i]) continue;
        q.push(i);
        chk[i] = 1;
        break;
    }

    while (!q.empty()) { // 선거구가 vis[i]인 지역들의 연결성 확인
        auto cur = q.front(); q.pop();
        for (auto nxt : adj[cur]) {
            if (chk[nxt]) continue; // 이미 방문했으면 넘기기
            if (!vis[nxt]) continue; // 다른 선거구라면 넘기기
            chk[nxt] = 1;
            q.push(nxt);
        }
    }
    // vis[i]인 모든 i가 chk[i] = 1 인지 확인 
    for (int i = 0; i < n; i++) if (vis[i] && !chk[i]) return false;

    // !vis[i] 선거구의 연결성 확인
    fill (chk, chk+15, 0);
    q = queue<int>();
    // !vis[i]인 i 찾기
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        q.push(i);
        chk[i] = 1;
        break;
    }
    
    while (!q.empty()) { // 선거구가 !vis[i]인 지역들의 연결성 확인
        auto cur = q.front(); q.pop();
        for (auto nxt : adj[cur]) {
            if (chk[nxt]) continue; // 이미 방문했으면 넘기기
            if (vis[nxt]) continue; // 다른 선거구라면 넘기기
            chk[nxt] = 1;
            q.push(nxt);
        }
    }

    // !vis[i]인 모든 i가 chk[i] = 1 인지 확인 
    for (int i = 0; i < n; i++) if (!vis[i] && !chk[i]) return false;
    
    return true;
}

void input () {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> population[i];
        tot += population[i];
    }

    // 각 구역과 인접한 구역의 정보
    for (int i = 0; i < n; i++) {
        int cnt; cin >> cnt;
        while (cnt--) {
            int m; cin >> m;
            adj[i].push_back(m-1);
        }
    }

    for (int i = 1; i < (1 << n)-1; i++) {
        fill (vis, vis+14, 0); 
        for (int k = 0; k < n; k++) { // 가능한 조합을 방문 처리
            if (i & (1 << k)) vis[k] = 1;
        }
        
        if (check()) { // 체크가 참이면 인구수를 센다
            int a = 0, b = 0;
            for (int j = 0; j < n; j++) {
                if (vis[j]) a += population[j];
                else b += population[j];
            }
            answer = min (answer, abs(a-b));
        }
    }

    if (answer >= MAX) cout << -1 << endl;
    else cout << answer << endl;
}

int main() {
    fastio;
    input();
}