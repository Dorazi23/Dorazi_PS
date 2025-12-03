#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define INF 0x3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n, k;
int arr[100005];
void input() {
    fastio;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> arr[i];
}

int res = -1e9;
void sliding_window(int st) {
    int tmp = 0;
    for (int i = st; i < st+k; i++) {
        tmp += arr[i];
    }
    res = max(res, tmp);
}

void ans() {
    for (int i = 0; i <= n-k; i++) {
        sliding_window(i);
    }
    cout << res << endl;
}

int main() {
    input();
    ans();
}