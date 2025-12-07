#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define INF 0x3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n;
vector<ll> len;
ll mn = 0x7f7f7f7f;
ll tot;

void input() {
    fastio; cin >> n;
    for (int i = 0; i < n-1; i++) {
        ll num; cin >> num;
        len.push_back(num);
    }
    
    
    for (int i = 0; i < n; i++) {
        ll tmp; cin >> tmp;
        if (tmp < mn) mn = tmp;
        tot += len[i] * mn;
    }

    cout << tot << endl;
}

int main() {
    input();
}