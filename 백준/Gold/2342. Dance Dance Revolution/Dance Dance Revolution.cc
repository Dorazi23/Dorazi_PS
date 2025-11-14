#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define INF 0x3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
vector<int> arr;
int cost[10][10];
int dp[100005][5][5];

int Cost (int x, int y) {
    if (x == 0) return 2; 
    if (x == y) return 1;
    if (abs(x-y) % 2 == 0) return 4;
    return 3;
}

void ans() {
    fastio;
    memset(dp, INF, sizeof(dp));

    // dp[k][i][j] = k 번째에서 왼발 i, 오른발 j일 때, 최소 힘
    
    dp[0][0][0] = 0;
    int idx = 0;
    while(1) {
        int n; cin >> n;
        if (n == 0) break;

        for (int i = 0; i < 5; i++) { // 왼발
            for (int j = 0; j < 5; j++) { // 오른발
                if (dp[idx][i][j] >= INF) continue;
                int lc = Cost(i, n); // i -> n
                int rc = Cost(j, n); // j -> n
                dp[idx+1][n][j] = min(dp[idx+1][n][j], dp[idx][i][j] + lc);
                dp[idx+1][i][n] = min(dp[idx+1][i][n], dp[idx][i][j] + rc);
            }
        }

        idx++;
    }

    int answer = INF;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            answer = min(answer, dp[idx][i][j]);
        }
    }

    cout << answer << endl;
    
}

int main() {
    ans();
}