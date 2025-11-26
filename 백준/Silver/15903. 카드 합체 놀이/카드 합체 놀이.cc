#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define INF 0x3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n, m;
priority_queue<ll, vector<ll>, greater<ll>> pq;
vector<ll> nlist;
    
int main() {
    fastio;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        ll num; cin >> num;
        pq.push(num);
    }

    // 숫자, 순서 
    while(m--) {
        if (pq.size() <= 1) break;
        ll x = pq.top(); pq.pop();
        ll y = pq.top(); pq.pop();

        ll res = x + y;
        pq.push(res);
        pq.push(res);
        
    }
    ll answer = 0;
    while (!pq.empty()) {
        ll cur = pq.top(); pq.pop();
        answer += cur;
    }

    cout << answer << endl;
}