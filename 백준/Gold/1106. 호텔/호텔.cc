#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000005
using namespace std;
int c, n;
int dp[1005];

void input() {
    memset(dp, INF, sizeof(dp));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> c >> n;
    for (int i = 0;  i< n; i++) {
        int cost, num; cin >> cost >> num;
        dp[num] = min(dp[num], cost);
    }
}

void ans() {
    for (int i = 1; i <= c; i++) {
        for (int j = 1; j < i; j++) { // 정확히 i명 만드는 비용
            dp[i] = min(dp[i], dp[j] + dp[i-j]);
        }

        for (int j = i+1; j <= 1000; j++) { // i명 초과를 만드는 비용이 더 싼 경우
            dp[i] = min(dp[i], dp[j]);
        }
        
    }
    
    cout << dp[c] << endl;
}

int main() {
    input();
    ans();
}