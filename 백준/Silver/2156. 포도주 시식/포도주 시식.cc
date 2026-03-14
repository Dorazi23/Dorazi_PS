#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define INF 0x3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n, arr[10005], dp[10005];

int main() {
    fastio;
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    dp[0] = arr[0];
    dp[1] = dp[0] + arr[1];
    dp[2] = max(max(dp[1], arr[1]+arr[2]), dp[0]+arr[2]);
        
    for (int i = 3; i < n; i++) {
        dp[i] = 0;
        dp[i] = max(max(dp[i-1], dp[i-2]+arr[i]), dp[i-3]+arr[i-1]+arr[i]);
    }
    cout << dp[n-1] << endl;
}