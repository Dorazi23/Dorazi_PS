#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define INF 0x7fffffff
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
string s1, s2;
vector<char> res; 
int dp[1005][1005];

void input() {
    fastio;
    cin >> s1 >> s2;
}

void ans() {
    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            if (s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    queue<pair<int,int>> q;
    q.push({s1.size(), s2.size()});
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        int i = cur.X, j = cur.Y;
        if (i == 0 || j == 0) break;
        if (dp[i][j] == dp[i-1][j]) q.push({i-1, j});
        else if (dp[i][j] == dp[i][j-1]) q.push({i, j-1});
        else {
            q.push({i-1, j-1});
            res.push_back(s1[i-1]);
        }
    }
    
    cout << dp[s1.size()][s2.size()] << endl;
    reverse(res.begin(), res.end());
    for (auto ch : res) {
        cout << ch;
    }
}

int main() {
    input();
    ans();
}