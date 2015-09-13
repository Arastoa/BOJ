#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int r, b; cin >> r >> b;
	int x, y;

	for (x = 1; x * ((r + 4) / 2 - x) != r+b; x++);

	cout << max(x, (r + 4) / 2 - x) << ' ' << min(x, (r + 4) / 2 - x) << endl;

	return 0;
}
