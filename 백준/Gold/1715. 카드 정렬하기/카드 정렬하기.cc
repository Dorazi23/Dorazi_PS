#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
int main() {
    fastio;
    int t; cin >> t;
    while(t--){
        int x; cin >> x;
        pq.push(x);
    }
    int answer = 0;
    while(pq.size() > 1){
        int x = pq.top(); pq.pop();
        int y = pq.top(); pq.pop();
        pq.push(x+y);
        answer += (x+y);
    }
    cout << answer << endl;
}