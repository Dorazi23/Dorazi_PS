#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n, m, h;
int dp[100][1005];
vector<int> block[100]; 

int main() {
    fastio;
    cin >> n >> m >> h;
    for (int i = 1; i <= n; i++) {
        int num;
        while(cin >> num){
            block[i].push_back(num);
            if(cin.get() == '\n') break;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (auto k : block[i]) {
            dp[i][k] = 1;
        }
    }

    for (int j = 1; j <= h; j++) {
        for (int i = 2; i <= n; i++) {
            dp[i][j] = (dp[i][j] + dp[i-1][j]) % 10007;
            for (auto k : block[i]) {
                if(j > k) dp[i][j] = (dp[i][j] + dp[i-1][j-k]) % 10007;   
            }
        }
    }
    cout << dp[n][h] % 10007 << endl;
}