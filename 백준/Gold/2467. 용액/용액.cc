#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000007
#define INF 0x3f3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ull = unsigned long long;
int n, mn = INT_MAX, i, j;
vector<int> arr;

void input () {
    cin >> n;
    while (n--) {
        int num; cin >> num;
        arr.push_back(num);
    }

    sort (arr.begin(), arr.end());
    int st = 0, en = arr.size() - 1;
    while (st < en) {
        int tar = arr[st] + arr[en];

        if (abs(tar) < mn) {
            mn = abs(tar);
            i = st, j = en;
        }
        
        if (tar == 0) {
            cout << arr[st] << " " << arr[en] << endl;
            return;
        }
        if (tar > 0) { // en--
            en--;
        }
        if (tar < 0) { // st++
            st++;
        }
    }

    cout << arr[i] << " " << arr[j] << endl;
} 

int main() {
    fastio; 
    input();
}