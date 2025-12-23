#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define INF 0x3f3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
int n;
string arr[10005];

string sum (string a, string b) {
    string result = "";
    int carry = 0;
    
    while (a.size() || b.size()) {
        int num1 = 0, num2 = 0;
        if (a.size()) {
            num1 = a.back() - '0';
            a.pop_back();
        }

        if (b.size()) {
            num2 = b.back() - '0';
            b.pop_back();
        }

        int currentSum = num1 + num2 + carry;
        result += to_string(currentSum % 10);
        carry = currentSum / 10;
    }

    if (carry) result += "1";
    reverse(result.begin(), result.end());
    return result;
}

void input() {
    fastio; cin >> n;
    arr[0] = "0", arr[1] = "1";
    for (int i = 2; i <= n; i++) {
        arr[i] = sum (arr[i-1], arr[i-2]);
    }
    cout << arr[n] << endl;
}

int main() {
    input();
}