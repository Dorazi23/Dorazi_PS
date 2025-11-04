#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
using ll = long long;
int n, m, mn = INF;
int arr[100005];

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void ans(){
    sort(arr, arr+n);
    int en = 0;
    for (int st = 0; st < n; st++) {
        while (en < n && arr[en]-arr[st] < m) en++;
        if(en == n) break;
        mn = min(mn, arr[en]-arr[st]);  
    }
    cout << mn << endl;
}

int main() {
    input();
    ans();
}