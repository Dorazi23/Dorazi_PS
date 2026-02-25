#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 0x4f4f4f4f
using namespace std;
using ll = long long;
int n, res = -1e9, arr[100005], dp[100005][3];

void input () {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    if (n == 1) {
        cout << arr[0] << endl;
        return;
    }
    
    dp[0][1] = arr[0];
    dp[0][0] = 0;
    for (int i = 1; i < n; i++) {
        dp[i][1] = max(arr[i], dp[i-1][1] + arr[i]);
        dp[i][0] = max(dp[i-1][1], dp[i-1][0] + arr[i]);
        res = max({res, dp[i][1], dp[i][0]});
    }

    cout << res << endl;
}

int main() {
    fastio;
    input();
}

/*
1. 테이블 정의
dp[i][1]: 삭제한 적 없을 때 최댓값
dp[i][0]: 삭제한 적 있을 때 최댓값

2. 점화식 수립
1) 삭제 한 적 없을 때
- 현재 원소부터 시작: arr[i]
- 이전 최적해에 현재 원소 붙이기: dp[i-1][1] + arr[i]
dp[i][1] = max(arr[i], dp[i-1][1] + arr[i])

2) 삭제 한 적 있을 때
- 현재 원소를 삭제할 때: dp[i-1][1]
- 이전에 삭제했을 때: dp[i-1][0] + arr[i]
dp[i][0] = max(dp[i-1][1], dp[i-1][0] + arr[i])
*/