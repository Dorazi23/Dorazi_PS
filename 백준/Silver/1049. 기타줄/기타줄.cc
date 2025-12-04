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

int answer = 0x3f3f3f;
int ma = 0x3f3f3f , mb = 0x3f3f3f;
void input() {
    fastio;
    cin >> n >> m;
    while(m--) {
        int a, b; cin >> a >> b;
        ma = min(ma, a);
        mb = min(mb, b);
    }
    int k = 0;
    if (n % 6 == 0) {
        k = n / 6;
        answer = min(answer, ma * k);
    }
    else { 
        k = n / 6;
        answer = min(answer, ma * k + (n-(6*k)) * mb);

        k++;
        answer = min(answer, ma * k);
    }
    
    answer = min(answer, mb * n);

    cout << answer << endl;
}

int main() {
    input();
}