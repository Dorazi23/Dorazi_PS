#include <bits/stdc++.h>
#define endl '\n'
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using namespace std;
ll arr[1000005], lis[1000005];
int main(void) {
    fastio;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    lis[0] = arr[0]; int len = 1;
    for (int i = 0; i < n; i++) {
        if(arr[i] > lis[len - 1]){
            lis[len++] = arr[i];
            continue;
        }
        int idx = lower_bound(lis, lis + len, arr[i]) - lis;
        lis[idx] = arr[i];
    }
    cout << len << endl;
}