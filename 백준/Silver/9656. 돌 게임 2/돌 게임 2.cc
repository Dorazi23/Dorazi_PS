#include <bits/stdc++.h>
#define endl '\n'
#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 0x4f4f4f4f
using namespace std;
int n;
void input () {
    cin >> n;

    if (n % 2 == 1) cout << "CY" << endl;
    else cout << "SK" << endl;
}

int main() {
    fastio;
    input();
}