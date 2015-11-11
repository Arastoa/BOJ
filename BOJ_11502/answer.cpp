#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int>pNums;
bool pNum[1001] = { false, };
void setting();
vector<int> result;
bool f(int index, int k);

int main() {
	int n; cin >> n;
	setting();
	while (n--) {
		int k; cin >> k;
		result.clear();
		if (f(0, k)) {
			sort(result.begin(), result.end());
			for (int i = 0; i < 3; i++) cout << result[i] << ' ';
			cout << endl;
		}
		else cout << 0 << endl;
	}

	return 0;
}

bool f(int index, int k) {
	bool ret = 0;
	if (result.size() == 2 && binary_search(pNums.begin(), pNums.end(), k)) {
		result.push_back(k);
		return true;
	}
	if (result.size() >= 2) {
		return false;
	}
	for (int i = index; pNums[i] < k ; i++) {
		result.push_back(pNums[i]);
		if ((ret|=f(i, k - pNums[i]))) break;
		result.pop_back();
	}
	return ret;
}

void setting() {
	int sqrtn = sqrt(1001);
	for (int i = 2; i <= sqrtn; i++)
		if (!pNum[i]) {
			pNums.push_back(i);
			for (int j = i*i; j < 1001; j += i)
				pNum[j] = true;
		}
	for (int i = sqrtn + 1; i < 1001; i++)
		if (!pNum[i])
			pNums.push_back(i);
}
