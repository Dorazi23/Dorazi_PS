#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000003
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n; int arr[1005], dp[1005], pre[1005];
vector<int> lis;

int main() {
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if(arr[j] < arr[i]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }

    int mxlen = 0, idx;
    for (int i = n-1; i >= 0; i--) {
        if(dp[i] > mxlen){
            mxlen = dp[i];
            idx = i;
        }
    }
    lis.push_back(arr[idx]);
    int len = mxlen;
    while(len > 1){
        //cout << arr[idx] << " " << len << endl;
        for (int i = idx; i >= 0; i--) {
            if(len-1 == dp[i] && arr[idx] > arr[i]){
                len -= 1;
                idx = i;
                lis.push_back(arr[idx]);
                break;
            }
        }
    }
    cout << mxlen << endl;
    reverse(lis.begin(), lis.end());
    for (auto i : lis) {
        cout << i << " ";
    }
}