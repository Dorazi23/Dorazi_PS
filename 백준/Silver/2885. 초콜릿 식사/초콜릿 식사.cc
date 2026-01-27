#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define INF 4e18
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int k, ans;

void input () {
    cin >> k;
    for (int i = 2; ; i=i*2) {
        if (i >= k) {
            ans = i;
            break;
        }
    }
    
    cout << ans << " ";
    if (ans == k) cout << 0 << endl;
    else {
        int cnt = 0;
        while (k > 0) {
            ans /= 2;
            cnt++;
            if (k - ans >= 0) k -= ans;
        }
        cout << cnt << endl;
    }
}

int main() {
    fastio;
    input();
}