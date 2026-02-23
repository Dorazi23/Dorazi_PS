#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 0x4f4f4f4f
using namespace std;
using ll = long long;
int n, k;
ll walkTime[105], walkMoney[105], bikeTime[105], bikeMoney[105];
ll dp[105][100005], answer;

void input() {
    memset(dp, -1, sizeof(dp));
    
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> walkTime[i] >> walkMoney[i] >> bikeTime[i] >> bikeMoney[i];
    }

    // 도보로 이동한 시간과 자전거로 이동한 시간이 동일할 수 있음 
    dp[0][walkTime[0]] = walkMoney[0];
    dp[0][bikeTime[0]] = max(dp[0][bikeTime[0]], bikeMoney[0]); 
    
    for (int i = 1; i < n; i++) {
        ll wt = walkTime[i], bt = bikeTime[i];
        ll wm = walkMoney[i], bm = bikeMoney[i];
        
        for (int j = k; j >= 0; j--) {
            if (j-wt >= 0 && dp[i-1][j-wt] != -1) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-wt] + wm);
            }
            if (j-bt >= 0 && dp[i-1][j-bt] != -1) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-bt] + bm);
            }
        }
    }

    for (int j = 0; j <= k; j++) {
        answer = max(answer, dp[n-1][j]);
    }
    cout << answer << endl;
}

int main() {
    fastio;
    input();
}