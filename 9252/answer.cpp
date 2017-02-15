#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <math.h>
#include <string>
#include <algorithm>
#include <string.h>
#include <vector>
#include <utility>
#include <functional>

#pragma warning(disable : 4996)
using namespace std;

const int ALPHABETS = 26;
int toNum(char ch) { return ch - 'A'; }
vector<char> vt;

const int SIZE = 1000;
int start;
int dp[SIZE + 1][SIZE + 1];
char a[SIZE + 1], b[SIZE + 1];

int lcs_bottomUp() {
	int strlenA = strlen(a), strlenB = strlen(b);
	for (int y = 0; y <= strlenB; y++)
		dp[strlenA][y] = 0;
	for (int x = strlenA - 1; x >= 0; x--) {
		dp[x][strlenB] = 0;
		for (int y = strlenB - 1; y >= 0; y--)
			if (a[x] == b[y])
			{
				dp[x][y] = 1 + dp[x + 1][y + 1];
			}
			else
			{
				dp[x][y] = max(dp[x + 1][y], dp[x][y + 1]);
				
			}
			//dp[x][y] = (a[x] == b[y]) ? 1 + dp[x + 1][y + 1] :
			//max(dp[x + 1][y], dp[x][y + 1]);
	}
	return dp[0][0];
}

void backTracking()
{
	int aLen = strlen(a), bLen = strlen(b);
	int aIdx = 0, bIdx = 0;
	while (aIdx < aLen && bIdx < bLen)
	{
		if (a[aIdx] == b[bIdx]) {
			vt.push_back(a[aIdx]);
			aIdx++;
			bIdx++;
		}
		else
		{
			if (dp[aIdx][bIdx] == dp[aIdx + 1][bIdx])
				aIdx++;
			else if (dp[aIdx][bIdx] == dp[aIdx][bIdx + 1] )
				bIdx++;
		}
	}
}

int main() {

	scanf("%s\n%s", a, b);
	if(strlen(a) < strlen(b))
		swap(a,b);
	int lcs = lcs_bottomUp();
	cout << lcs << endl;
	int	idx = lcs;

	backTracking();
	for (int i = 0; i < vt.size(); i++)
		cout << vt[i];
	cout << endl;

	return 0;
}
