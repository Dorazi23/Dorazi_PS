#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
int t;
bool prime[1000005];
int main() {
    fastio;
    cin >> t;
    prime[1] = 1;
    for (int i = 2; i*i <= MAX; i++) {
        if(prime[i]) continue;
        for (int j = i*i; j <= MAX; j += i) {
            prime[j] = 1;
        }
    }
    for (int i = 0; i < t; i++) {
        int n, cnt = 0; cin >> n;
        for (int j = 2; j < n/2+1; j++) {
            if(prime[j] || prime[n-j]) continue;
            cnt++;
        }
        cout << cnt << endl;
    }
}