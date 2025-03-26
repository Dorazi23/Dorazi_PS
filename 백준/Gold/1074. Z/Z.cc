#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n, r, c;
int ans = 0;

void func(int x, int y, int size){
    if(c==x && r==y){         cout << ans;
        return;
    }
    else if (c < x + size && r < y + size && c >= x && r >= y){
        func(x, y, size / 2);
        func(x + size / 2, y, size / 2);
        func(x, y + size / 2, size / 2);
        func(x + size / 2, y + size / 2, size / 2);
    }else{ // 없다면 숫자 카운트 -> 정사각형 넓이
        ans += size * size;
    }
}
int main(){
    cin >> n >> r >> c;
    func(0, 0, pow(2, n));
    return 0;
}
