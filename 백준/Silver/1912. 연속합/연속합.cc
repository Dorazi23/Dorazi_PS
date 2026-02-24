#include <iostream>
#include <algorithm>
using namespace std;

long long arr[100005];
long long d[100005];
int main() {
    int n; cin >> n;
    long long ret = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    d[0] = arr[0];
    ret  = arr[0];
    for (int i = 1; i < n; i++) {
        d[i] = max(d[i-1] + arr[i], arr[i]);
        ret = max(d[i],ret);
    }
    cout << ret << '\n';
}

