#include <bits/stdc++.h>
#define endl '\n'
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

void func(int a, int b, int n){ //n개의 원판을 a -> b로 옮긴다
    if(n == 1){
        cout << a << " " << b << endl;
        return;
    }
    func(a, 6-a-b, n-1);
    cout << a << " " << b << endl;
    func(6-a-b, b, n-1);
}

int main() {
    int n; cin >> n;
    string a = to_string(pow(2, n));
    int x = a.find('.');				
	a = a.substr(0, x);				
	a[a.length() - 1] -= 1;				
	cout << a << endl;
    if(n <= 20){
        func(1, 3, n);
    }
}
/*
하노이 탑
1번: a
2번: 6-a-b
3번: b
n-1개의 원판을 2번 기둥에 옮긴다
n번째 원판을 3번 기둥에 옮긴다
다시 n-1개의 원판을 3번 기둥에 옮긴다
*/