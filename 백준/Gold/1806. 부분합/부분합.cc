#include <bits/stdc++.h>
#define endl '\n'
#define INF 0x3fffffff
using namespace std;
int n, s;
int arr[100005];
int mn = INF;
int tot = 0;

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> s;
    for (int i = 0; i < n; i++) cin >> arr[i];
}

void ans(){
    int en = 0; tot = arr[0];
    for (int st = 0; st < n; st++) {
        while(en < n && tot < s){
            en++;
            tot += arr[en];
        }
        if (en == n) break;
        mn = min(mn, en-st+1);
        tot -= arr[st];
    }

    if (mn != INF) cout << mn << endl;
    else cout << "0" << endl;
}

int main() {
    input();
    ans();
}