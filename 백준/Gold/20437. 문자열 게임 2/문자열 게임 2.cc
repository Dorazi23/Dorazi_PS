#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define INF 0x3f3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
string w;
int t, k, mx, mn;

void input () {
    vector<int> idx[26];
    
    cin >> w >> k;

    for (int i = 0; i < w.size(); i++) {
        idx[w[i] - 'a'].push_back(i);
    }
    // aaaba 
    // idx[i] = {0, 1, 2, 4}
    // k = 4
    // j ~ j+k-1
    // j+k-1 == size - 1

    int mx = -1000, mn = INT_MAX;
    for (int i = 0; i < 26; i++) {
        if (idx[i].size() < k) continue;

        for (int j = 0; j <= idx[i].size() - k; j++) {
            int st = idx[i][j], en = idx[i][j+k-1];
            int len = en-st + 1;

            mx = max(mx, len);
            mn = min(mn, len);
        }
    }

    if (mx == -1000) cout << "-1" << endl;
    else cout << mn << " " << mx << endl;
}

int main() {
    fastio; cin >> t;
    while (t--) {
        input();
    }
}