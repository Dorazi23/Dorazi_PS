#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define INF 0x3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int dp[1005][1005];
int n, m;
string arr[1005];
int main() {
    memset(dp, 0, sizeof(dp));
    fastio;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(arr[i][j] == '1'){ //색칠된 곳 
                if(i == 0 || j == 0){
                    dp[i][j] = 1;
                    continue;
                }

                if(dp[i-1][j] * dp[i][j-1] * dp[i-1][j-1] != 0){
                    dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]), dp[i-1][j-1]) + 1; 
                }
                else{
                    //dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]), dp[i-1][j-1]);
                    dp[i][j] = 1;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans*ans << endl;
}