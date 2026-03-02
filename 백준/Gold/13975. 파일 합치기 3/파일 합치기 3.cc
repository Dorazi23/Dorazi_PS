#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 0x4f4f4f4f
using namespace std;
using ll = long long;

void input () {
    priority_queue<ll, vector<ll>, greater<ll>> minHeap;
    ll answer = 0;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int m; cin >> m; 
        minHeap.push(m);
    }

    while (minHeap.size() > 1) {
        ll a = minHeap.top(); minHeap.pop();
        ll b = minHeap.top(); minHeap.pop();
        answer += (a+b);
        minHeap.push(a+b);
    }

    cout << answer << endl;
}

int main() {
    fastio;
    int t; cin >> t;
    while (t--) {
        input();   
    }
}