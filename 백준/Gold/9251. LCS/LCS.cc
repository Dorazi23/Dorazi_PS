#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 100000
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
string s1, s2;
int dp[1005][1005];
int main() {
    fastio;
    cin >> s1 >> s2;
    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[s1.size()][s2.size()];
}