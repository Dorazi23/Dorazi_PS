#include <bits/stdc++.h>
#define endl '\n'
#define fastio cin.tie(0)->sync_with_stdio(0)
#define X first
#define Y second
using ll = long long int;
using namespace std;
int a, b, ans = -1;
int main() {
    fastio;
    queue<pair<ll,int>> q;
    cin >> a >> b;
    q.push({a,1});
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        ll x = cur.X;
        int cnt = cur.Y;
        if(x == b){
            ans = cnt;
            break;
        }

        if(2*x <= 1e9){
            q.push({2*x, cnt + 1});
        }

        if(x*10+1 <= 1e9){
            q.push({x*10+1, cnt + 1});
        }
    }
    cout << ans << endl;
}