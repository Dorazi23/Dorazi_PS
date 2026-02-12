#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define fastio cin.tie(0)->sync_with_stdio(0)
#define MAX 1000000000
#define INF 4e18
using namespace std;
using ll = long long;
int q;
string s;
vector<int> dp[30];

void input () {
    cin >> s >> q;
    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];
        dp[ch-'a'].push_back(i);
    }
    
    while (q--) {
        char ch; int l, r, cnt = 0;
        cin >> ch >> l >> r;

        for (auto x : dp[ch-'a']) if (l <= x && x <= r) cnt++;
        cout << cnt << endl;
    }
    
}

int main() {
    fastio;
    input();
}