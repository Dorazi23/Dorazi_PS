#include <bits/stdc++.h>
#define endl '\n'
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using namespace std;
ll n, c;
ll arr[200005];

bool check(ll x){
    ll cur = 1;
    ll last = arr[0];
    for (int i = 1; i < n; i++) {
        ll dist = arr[i] - last;
        if(dist >= x){
            last = arr[i];
            cur++;
        }
    }
    return cur >= c;
}

int main() {
    fastio;
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr,arr+n);
    ll st = 1, en = 1e9+10;
    while(st + 1 < en){
        ll md = (st + en) / 2;
        if(check(md)){
            st = md;
        }
        else{
            en = md;
        }
    }
    cout << st << endl;
}