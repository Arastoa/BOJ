#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define INF 987654321

using namespace std;

int n;
int result = INF;
void findPow(int sum, int cnt);

int main() {
	
	cin >> n;
	findPow(n, 0);
	cout << result << endl;

	return 0;
}

void findPow(int sum,int cnt) {
	if (cnt >= result) return;
	if (sum == 0){
		result = min(result, cnt);
		return;
	}

	int p = sqrt(sum);
	for (int m = p; m > p/2 && m>0; m--)
		findPow(sum - m*m, cnt + 1);
}
