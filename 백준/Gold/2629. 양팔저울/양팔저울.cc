#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 0x4f4f4f4f
using namespace std;
using ll = long long;
int n, m, weight[1005], bead[1005];
bool dp[105][40005];

void input () {
    cin >> n;  // 추의 개수 
    for (int i = 0; i < n; i++) cin >> weight[i];

    dp[0][0] = dp[0][weight[0]] = 1;
    for (int i = 1; i < n; i++) {
        dp[i][weight[i]] = 1;
        for (int j = 1; j <= 15000; j++) {
            if (j-weight[i] >= 0) {
                if (dp[i-1][j-weight[i]]) dp[i][j] = 1; // 왼쪽에 다는 경우 
            }
            if (dp[i-1][j]) {
                dp[i][abs(j-weight[i])] = 1; // 오른쪽에 다는 경우
                dp[i][j] = 1; // 안 다는 경우
            }
        }
    }
    
    cin >> m; // 구슬의 개수 
    while (m--) {
        int x; cin >> x;
        if (x > 15000) cout << "N ";
        else if (dp[n-1][x]) cout << "Y ";
        else cout << "N ";
    }
    
}

int main() {
    fastio;
    input();
}