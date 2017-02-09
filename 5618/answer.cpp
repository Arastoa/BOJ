#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

int main() {
	int n; cin >> n;
	vector<int> vt;
	vector<int> arr(n);

	vt.push_back(1);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());
	int limit = arr[n - 1] / 2;//sqrt(arr[n - 1]);


	
	for (int i = 2; i <= limit; i++)
		for (int j = 0; j < n; j++) {
			if (arr[j] % i != 0)
				break;

			if (j == n - 1)
				vt.push_back(i);
		}

	int length = vt.size();
	for (int i = 0; i < length; i++)
		cout << vt[i] << endl;

	return 0;
}
