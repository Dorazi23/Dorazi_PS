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
ll m, sum;
int arr[100005];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];
    int en = 0;
    for (int st = 0; st < n; st++) {
        sum = arr[st];
        en = st;
        while (en < n && sum <= m) {
            if (sum == m) answer++;
            en++;
            sum += arr[en];
        }
    }

    cout << answer << endl;
}