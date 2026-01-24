#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
ll ans = 0;
int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n; cin >> n;
    stack<ll> s;
    while(n--){
        ll input; cin >> input;
        while(!s.empty()){
            if(s.top() > input){
                ans += s.size();
                break;
            }
            s.pop();
        }
        s.push(input);
    }
    cout << ans << endl;
}