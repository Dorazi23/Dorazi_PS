#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n; ll b;

ll arr[6][6];
ll ans[6][6];

void square(ll x[6][6], ll y[6][6]){
    // 연산 결과를 임시로 저장
    ll temp[15][15];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = 0;
        }
    }
        
    // 제곱 연산
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ll sum = 0;
            for (int k = 0; k < n; k++) {
                sum += (x[i][k] * y[k][j]) % 1000;
            }
            temp[i][j] = sum % 1000;
        }
    }

    // 연산 결과를 업데이트
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            x[i][j] = temp[i][j] % 1000;
        }
    }
}

int main() {
    cin >> n >> b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
        ans[i][i] = 1;
    }

    while(b > 0){
        if (b % 2 == 1){
            square(ans, arr);
        }
        square(arr, arr);
        b = b / 2;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}