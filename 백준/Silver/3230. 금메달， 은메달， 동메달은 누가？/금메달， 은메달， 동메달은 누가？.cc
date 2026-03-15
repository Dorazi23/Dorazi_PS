#include <bits/stdc++.h>
#define endl '\n'
#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 0x4f4f4f4f
using namespace std;
int n, m, r, temp;
int arr[101], ans[101];

void input() {
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> r;

        if (arr[r] != 0 && i != 1) {
            for (int j = i - 1; j >= r; j--) arr[j + 1] = arr[j];
            arr[r] = i;
        }
        else arr[r] = i; 
    }

    for (int i = 1; i <= m; i++) {
        cin >> r;
        int p = arr[m-i+1];

        if (ans[r] != 0 && i != 1) {
            for (int j = i - 1; j >= r; j--) {
                ans[j + 1] = ans[j];
            }
            ans[r] = p;
        }
        else ans[r] = p;
    }

    for (int i = 1; i <= 3; i++) cout << ans[i] << endl;
}

int main() {
    fastio;
    input();
}