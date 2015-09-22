#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		bool flag = false;
		int n; cin >> n;
		vector<string> vt(n);
		for (int i = 0; i < n; i++) {
			cin >> vt[i];
		}
		for (int i = 0; i < n && !flag; i++) {
			for (int j = i + 1; j < n; j++) {
				string temp = vt[i] + vt[j];
				string r=temp; reverse(r.begin(), r.end());
				if (r == temp) {
					cout << temp << endl;
					flag = true;
					break;
				}
				temp = vt[j] + vt[i];
				r = temp; reverse(r.begin(), r.end());
				if (r == temp) {
					cout << temp << endl;
					flag = true;
					break;
				}
			}
		}
		if (!flag) cout << 0 << endl;
	}

	return 0;
}
