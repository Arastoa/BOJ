#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#pragma warning (disable : 4996)
using namespace std;

const int ALPHABETS = 26;
int toNum(char ch) { return ch - 'A'; }

const int SIZE = 1000;
int dp[SIZE + 1][SIZE + 1];
char a[SIZE + 1], b[SIZE + 1];

int lcs_bottomUp(){
	int strlenA = strlen(a), strlenB = strlen(b);
	for (int y = 0; y <= strlenB; y++)
		dp[strlenA][y] = 0;
	for (int x = strlenA - 1; x >= 0; x--){
		dp[x][strlenB] = 0;
		for (int y = strlenB - 1; y >= 0; y--)
			dp[x][y] = (a[x] == b[y]) ? 1 + dp[x + 1][y + 1] :
			max(dp[x + 1][y], dp[x][y + 1]);
	}
	return dp[0][0];
}


int main(){
	
	scanf("%s\n%s", a, b);
	cout << lcs_bottomUp() << endl;
	return 0;
}
