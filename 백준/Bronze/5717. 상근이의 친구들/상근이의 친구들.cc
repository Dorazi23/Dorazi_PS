#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int x, y; cin >> x >> y;
	while (x != 0 || y != 0) {
		cout << x + y << '\n';
		cin >> x >> y;
	}
}