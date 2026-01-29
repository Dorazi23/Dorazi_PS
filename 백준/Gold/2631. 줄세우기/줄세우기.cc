#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define INF 4e18
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n, arr[205], lis[205];

void input () {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    int len = 1;
    lis[0] = arr[0];
    for (int i = 1; i < n; i++) {
        if (lis[len-1] < arr[i]) lis[len++] = arr[i];
        else {
            int idx = lower_bound(lis, lis+len, arr[i]) - lis;
            lis[idx] = arr[i];
        }
    }

    cout << n - len << endl;
}

int main() {
    fastio;
    input();
}