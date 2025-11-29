#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define INF 0x3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n, answer;
int a[10005], b[10005];

int main() {
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(a, a+n); 
    sort(b, b+n, greater<>());
    for (int i = 0; i < n; i++) {
        answer += a[i] * b[i];
    }
    cout << answer << endl;
}