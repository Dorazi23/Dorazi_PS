#include <bits/stdc++.h>
#define endl '\n'
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n, m, k;
ll seg[4000005], arr[1000005];

ll sum (int idx, int st, int en, int l, int r) {
    if (r < st || l > en) return 0;
    if (l <= st && en <= r) return seg[idx];

    int md = (st+en)/2;
    return sum (2*idx, st, md, l, r) + sum (2*idx+1, md+1, en, l, r);
}

void update (int idx, int st, int en, int i, ll diff) {
    if (st == en) {
        seg[idx] += diff;
        return;
    }

    int md = (st+en)/2;
    if (i <= (st+en)/2) update(2*idx, st, md, i, diff); 
    else update(2*idx+1, md+1, en, i, diff);

    seg[idx] = seg[2*idx] + seg[2*idx+1];
}

void build(int idx, int st, int en) {
    if (st == en) {
        seg[idx] = arr[st];
        return;
    }
    int mid = (st + en) / 2;
    build(2*idx, st, mid);
    build(2*idx+1, mid+1, en);
    seg[idx] = seg[2*idx] + seg[2*idx+1];  
}

void input () {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    build(1, 1, n);

    int x = m+k;
    while (x--) {
        ll a, b, c; cin >> a >> b >> c;
        if (a == 1) {
            ll diff = c - arr[b];
            arr[b] = c;
            update(1, 1, n, b, diff);
        }
        else {
            cout << sum(1, 1, n, b, c) << endl;
        }
    }
}

int main() {
    fastio;
    input();
}