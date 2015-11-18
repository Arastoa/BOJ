#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

vector<int> plums;
int cache[1000][30];
int eatPlum(int index, int p,int t);
int n, m;

int main() {
	memset(cache, -1, sizeof(cache));
	cin >> n >> m;
	plums.assign(n,0);
	for (int i = 0; i < n; i++)
		cin>>plums[i];
	
	cout << max(eatPlum(0, 1,0),eatPlum(0,2,1)) << endl;
	return 0;
}

int eatPlum(int index, int p,int t) {
	if (index == n) return 0;
	int& ret = cache[index][t];
	if (ret != -1) return ret;
	ret = 0;
	ret = max(ret, eatPlum(index + 1, p, t) + (plums[index] == p));
	if (plums[index] != p && t<m)
		ret=max(ret,eatPlum(index, (p == 1 ? 2 : 1), t + 1));
	return ret;
}
