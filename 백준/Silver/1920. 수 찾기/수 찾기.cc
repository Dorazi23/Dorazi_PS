#include <bits/stdc++.h>
#define endl '\n'
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
int n, m, arr[100005];

void input () {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);

    cin >> m;
    while (m--) {
        int num; cin >> num;
        int idx = lower_bound(arr, arr+n, num) - arr;
        if (idx < n && arr[idx] == num) cout << 1 << endl;
        else cout << 0 << endl;
    }
}

int main() {
    fastio;
    input();
}