#include <bits/stdc++.h>
#define endl '\n'
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using namespace std;
int n;
ll arr[100005]; 
ll standard = LLONG_MAX;
ll ans1, ans2;
int main(){
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        ll tar1 = arr[i];
        ll st = 0, en = n;
        while(st + 1 < en){
            ll md = (st + en) / 2;
            ll tar2 = arr[md];
            ll sum = tar1 + tar2;
            if(tar1 != tar2 && abs(sum) < standard){
                standard = abs(sum);
                if(tar2 > tar1){
                    ans1 = tar1;
                    ans2 = tar2;
                }
                else{
                    ans1 = tar2;
                    ans2 = tar1;
                }
            }
            if(sum > 0){
                en = md;
            }
            else{
                st = md;
            }
        }
    }
    cout << ans1 << " " << ans2 << endl;
}