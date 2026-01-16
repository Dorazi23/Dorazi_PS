#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000007
#define INF 0x3f3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n;
int W[105][105];
int dp[25][1<<17];

void input () {
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> W[i][j];
        }
    }

    dp[0][1] = 0;

    // bitmask: 지금까지 방문한 도시 
    for (int bitmask = 2; bitmask < (1 << n); bitmask++) {
        vector<int> VisitedList;

        // bitmask라는 경로 중에서 어떤 도시를 마지막으로 할 것인가?
        // 마지막 도시가 가능한 곳은 이미 방문한 곳이어야 한다
        // 즉, i번째 도시가 비트에서 1이어야 한다
        for (int i = 0; i < n; i++) {
            if (bitmask & (1 << i)) {
                VisitedList.push_back(i);
            }
        }

        for (auto const &cur_city : VisitedList) {
            int tmp = bitmask ^ (1 << cur_city);
    
            for (int prev_city = 0; prev_city < n; prev_city++) {
                if (dp[prev_city][tmp] == -1 || W[prev_city][cur_city] == 0) continue;
                
                if (dp[cur_city][bitmask] == -1){
                    dp[cur_city][bitmask] = dp[prev_city][tmp] + W[prev_city][cur_city];
                }
                else {
                    dp[cur_city][bitmask] = min(dp[cur_city][bitmask], dp[prev_city][tmp] + W[prev_city][cur_city]);
                }
            }
            
        }
    }

    int mn = INF;
    // dp[i][(1 << n)-1]: i에서 출발하여 모든 도시를 돈 경우
    // (1 << n)-1 = 1111...111 (n개)
    for (int i = 0; i < n; i++) { 
        if (dp[i][(1 << n)-1] == -1 || W[i][0] == 0) continue;
        mn = min(mn, dp[i][(1 << n)-1] + W[i][0]);
    }

    cout << mn << endl;
}

int main() {
    fastio;
    input();
}