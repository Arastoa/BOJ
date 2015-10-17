#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <vector>
#define DIV 10007

using namespace std;

int cache[1000][10];
int acs(int l, int num);
int n;
int main() {
	memset(cache, -1, sizeof(cache));
	cin >> n; n--;
	int result = 0;
	for (int i = 0; i < 10; i++)
		result = (result + acs(0, i)) % DIV;
	cout << result << endl;

	return 0;
}


int acs(int l, int num) {
	if (l == n) return 1;
	int& ret = cache[l][num];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = num; i <= 9; i++)
		ret = (ret + acs(l + 1, i)) % DIV;

	return ret;
}
