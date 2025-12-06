#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define INF 0x3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int t;

void input() {
    fastio;
    cin >> t;
    while(t--) {
        ll num; cin >> num;
        if (num <= 2) {
            cout << "2" << endl;
            continue;
        }
        
        while(1) {
            bool flag = 0;
            for (ll i = 2; i <= sqrt(num); i++) {
                if (num % i == 0) {
                    flag = 1;
                    break;
                }
            }
    
            if (!flag) {
                cout << num << endl; 
                break;
            }
            else num++;    
        }
    }
}

int main() {
    input();
}