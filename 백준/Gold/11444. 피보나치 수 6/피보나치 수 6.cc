#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000007
#define INF 0x3f3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ull = unsigned long long;
ull n;
map<ull, ull> F;

ull func (ull x) {
    if (x == 0) return 0;
    if (x == 1) return 1;
    if (x == 2) return 1;
    if (F.count(x)) return F[x];
    if (x % 2 == 0) {
        ull m = x/2;
        ull tmp1 = func(m-1);
        ull tmp2 = func(m);
        F[x] = ((2LL * tmp1 + tmp2) * tmp2) % MAX;
        return F[x];
    }

    ull m = (x+1)/2;
    ull tmp1 = func(m-1);
    ull tmp2 = func(m);
    F[x] = (tmp1 * tmp1 + tmp2 * tmp2) % MAX;
    return F[x];
} 

void input() {
    cin >> n;
    cout << func(n);
}

int main() {
    fastio;
    input();
}