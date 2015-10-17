#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t; cin >> t;
	int c = 1;
	while (t--) {
		int n; cin >> n;
		vector<long long> vt(n);
		for (int i = 0; i < n; i++) cin >> vt[i];
		while (vt.size() > 2) {
			int s = vt.size();
			vector<long long> tmp;
			for (int i = 0; i < s / 2; i++) tmp.push_back(vt[i] + vt[s - 1 - i]);
			if (s % 2 == 1) tmp.push_back(vt[s / 2] * 2);
			vt = tmp;
		}
		cout << "Case #" << c++ << ": ";
		if (vt[0] > vt[1]) cout << "Alice" << endl;
		else cout << "Bob" << endl;
	}


	return 0;
}
