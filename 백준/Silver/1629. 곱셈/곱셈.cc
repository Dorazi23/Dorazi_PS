#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll a, b, c;

ll func(ll a, ll b, ll c){
    if(b == 0){
        return 1;
    }
    if(b == 1){
        return a % c;
    }
    
    ll val = func(a, b/2, c);
    
    if(b % 2 == 0){
        return (val*val) % c;
    }
    else{
        return (((val*val)%c)*a) % c;
    }
    
}

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> a >> b >> c;
    cout << func(a,b,c) % c;
}