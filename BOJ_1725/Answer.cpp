#include <iostream>
#include <vector>

using namespace std;

vector<int> h;

int solve(int left, int right);
int max(int a, int b);
int min(int a, int b);

int main(void){
	int n, data;
	
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> data;
		h.push_back(data);
	}

	cout << solve(0, n-1) << endl;

	return 0;
}

int max(int a, int b){
	return a > b ? a : b;
}

int min(int a, int b){
	return a < b ? a : b;
}

int solve(int left, int right){
	if (right == left) return h[left];


	int mid = (right + left) / 2;
	int ret = max(solve(left, mid), solve(mid + 1, right));

	int lo = mid, hi = mid + 1;
	int height = min(h[lo], h[hi]);
	ret = max(ret, height * 2);

	while (left < lo || hi < right){
		if (hi < right && (lo == left || h[lo - 1] < h[hi + 1])){
			hi++;
			height = min(height, h[hi]);
		}
		else{
			--lo;
			height = min(height, h[lo]);
		}
		ret = max(ret, height*(hi - lo + 1));

	}
	return ret;
}
