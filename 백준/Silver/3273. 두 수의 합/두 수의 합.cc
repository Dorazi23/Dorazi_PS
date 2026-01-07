#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define INF 0x3f3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n, cnt;
ll tar;
vector<ll> v;

void input () {
    fastio; cin >> n;
    for (int i = 0; i < n; i++) {
        ll num; cin >> num;
        v.push_back(num);
    }
    cin >> tar;
    sort (v.begin(), v.end());
}

void ans () {
    int i = 0, j = n - 1;
    while (i < j) {
        if (v[i] + v[j] == tar) {
            cnt++; 
            i++;
            j--;
        }
            
        else if (v[i] + v[j] < tar) {
            i++;
        }
            
        else {
            j--;
        }
    }

    cout << cnt << endl;
}

int main() {
    input();
    ans();
}