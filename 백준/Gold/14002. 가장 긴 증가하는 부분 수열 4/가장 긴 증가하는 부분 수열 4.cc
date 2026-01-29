#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define INF 4e18
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
vector<int> lis, v;
int n, arr[1005], len[1005];

void input () {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    lis.push_back(arr[0]);
    len[0] = 1;
    for (int i = 1; i < n; i++) {
        if (lis[lis.size()-1] < arr[i]) {
            lis.push_back(arr[i]);
            len[i] = lis.size();
        }
        else {
            int idx = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
            lis[idx] = arr[i];
            len[i] = idx + 1;
        }
    }

    int res = lis.size();
    cout << res << endl;
    for (int i = n-1; i >= 0; i--) {
        if (len[i] == res) {
            res--;
            v.push_back(i);   
        }
    }

    for (int i = v.size()-1; i >= 0; i--) cout << arr[v[i]] << " ";
}

int main() {
    fastio;
    input();
}