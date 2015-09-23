#include <iostream>
#include <string.h>

using namespace std;

int cache[2501][2501];
int bracket(int s, int l);

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		memset(cache, -1, sizeof(cache));
		if (n == 1 || n%2==1) {
			cout << 0 << endl;
			continue;
		}
		cout <<bracket(n/2, n/2)<<endl;
	}
	return 0;
}

int bracket(int s, int l) {
	if (s == 0 && l == 0)
		return 1;

	int& ret = cache[s][l];
	if (ret != -1) return ret;

	ret = 0;
	if (s > 0) ret += bracket(s - 1, l);
	ret %= 1000000007;
	if (s < l) ret += bracket(s, l - 1);

	ret %= 1000000007;
	return ret;
}
