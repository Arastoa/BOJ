#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

char field[65][65];
string quadTree(int y, int x, int width);

int main() {
	int n; cin >> n;

	getchar();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			field[i][j] = getchar();
		getchar();
	}
	
	cout << quadTree(0, 0, n/2) << endl;

	return 0;
}

string quadTree(int y, int x, int width) {
	string ret = "";

	if (width == 1) {
		ret = string(1, field[y][x]) + string(1, field[y][x + 1]) + string(1, field[y + 1][x]) + string(1, field[y + 1][x + 1]);
		if (ret == "1111") ret = "1";
		else if (ret == "0000") ret = "0";
		else ret = "(" + ret + ")";
		return ret;
	}

	ret += quadTree(y, x, width/2);
	ret += quadTree(y, x + width, width / 2);
	ret += quadTree(y + width, x, width / 2);
	ret += quadTree(y + width, x + width, width / 2);


	if (ret == "1111") ret = "1";
	else if (ret == "0000") ret = "0";
	else ret = "(" + ret + ")";
	return ret;
}
