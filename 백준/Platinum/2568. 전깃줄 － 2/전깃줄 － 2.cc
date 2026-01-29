#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define INF 4e18
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n, mx = -100, arr[500005], lis[500005], lastLen[500005];
vector<int> tmp(500005, -1), tmp2(500005, -1), v;

void input () {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        tmp[a] = b;
        tmp2[b] = a;
    }

    int idx = 0;
    for (int i = 1; i <= 500000; i++) {
        if (tmp[i] == -1) continue;
        arr[idx++] = tmp[i];
    }
    
    int len = 1;
    lastLen[0] = 1;
    lis[0] = arr[0];
    for (int i = 1; i < n; i++) {
        if (lis[len-1] < arr[i]) {
            lis[len++] = arr[i];
            lastLen[i] = len;
        }
        int idx = lower_bound(lis, lis+len, arr[i]) - lis;
        lis[idx] = arr[i];
        lastLen[i] = idx + 1;
    }

    cout << n - len << endl;
    for (int i = n-1; i >= 0; i--) {
        if (lastLen[i] == len) len--;
        else v.push_back(tmp2[arr[i]]);
    }

    sort(v.begin(), v.end());
    for (auto x : v) cout << x << endl;
}

int main() {
    fastio;
    input();
}