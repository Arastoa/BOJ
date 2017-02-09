#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

double cache[1 << 20] = { 0, };
double mission[20][20] = { 0, };
double complete(int jimmy, int masking);
int N;

int main() {

	cin >> N;
	for (int j = 0; j < 1<<20; j++)
		cache[j] = -1;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> mission[i][j];
			mission[i][j] /= 100.0;
		}

	double result = 0;

	result = complete(0, 0);

	printf("%.6lf\n", result * 100);
	//cout << result * 100 << endl;
	return 0;
}

double complete(int jimmy, int masking)
{
	if (jimmy == (N)) return 1;
	double& ret = cache[masking];
	if (ret > -1) return ret;
	ret = 0;

	for (int i = 0; i < N; i++)
		if ((masking & (1 << i)) == 0)
			ret = max(ret, mission[jimmy][i] *  complete(jimmy+1, (masking | (1 << i))));

	return ret;
}
