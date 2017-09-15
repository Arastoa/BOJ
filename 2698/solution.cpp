#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <map>
#include <set>
#include <math.h>
#include <string>
#include <algorithm>
#include <string.h>
#include <vector>
#include <utility>
#include <stack>
#include <functional>
#include <list>
#include <cstdio>
#include <cstring>

#define INF 987654321
#define DIV 14579
#define MAX_SIZE 501
#pragma warning(disable : 4996)
using namespace std;

int n, k; 
int cache[102][101][2];

int solution(int pos, int cur, int count) {
	if (pos == n)
		return (count == k);

	int& ret = cache[pos][count][cur];
	if (ret != -1) return ret;

	ret = 0;
	ret += solution(pos + 1, 1, (cur == 1 ? count+1 : count));
	ret += solution(pos + 1, 0, count);


	return ret;
}

int main() {
	int t; cin >> t;
	while (t--) {
		memset(cache, -1, sizeof(cache));
		cin >> n >> k;
		cout << solution(0, 0, 0) << endl;
	}
	return 0;
}
