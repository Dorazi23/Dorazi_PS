#include <bits/stdc++.h>
#define endl '\n'
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using namespace std;
int main(void) {
    fastio;
    int arr[1001];
    int lis[1001];
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
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