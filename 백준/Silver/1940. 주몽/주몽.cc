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
int arr[20000];

void input() {
    fastio;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; 
    }
}

int cnt;
void ans() {
    sort(arr, arr+n);

    
    for (int st = 0; st < n; st++) {
        int en = n-1;
        int tot = arr[st] + arr[en];
        while(tot >= m && st < en) {
            
            tot = arr[st] + arr[en];
            if (tot == m){ 
                cnt++;
            }
            en--;
        }
    }

    cout << cnt << endl;
}

int main() {
    input();
    ans();
}