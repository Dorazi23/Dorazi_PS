#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define INF 0x3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n;
bool isPrime[4000005];
vector<int> vPrime;

void input () {
    fastio;
    cin >> n;
}

void Prime() {
    for (int i = 2; i <= 4000005; i++) {
        if (!isPrime[i]) { // 소수 일 때 
            vPrime.push_back(i);
            for (int j = 2; j <= 4000005; j++) {
                if (i*j >= 4000005) break;
                isPrime[i*j] = true;
            }
        }
    }

}



void ans() {
    int answer = 0;
    for (int i = 0; i < vPrime.size(); i++) {
        if (n < vPrime[i]) break;
        int tmp = i;
        int sum = 0;
        while (sum < n && tmp < vPrime.size()) {
            sum += vPrime[tmp++];
            if (sum == n) answer++;
        }
    }
    cout << answer << endl;
}

int main() {
    input();
    Prime();
    ans();
}