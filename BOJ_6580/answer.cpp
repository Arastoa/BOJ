#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string>
#include <math.h>
#pragma warning(disable : 4996)

using namespace std;

bool field[512][512];
string quadtree(int y, int x, int n);

int main() {
	string str; int h, w;

	for (int i = 0; i < 2; i++) {
		cin >> str; cin >> str; cin >> h;
	}
	w = h / 8;

	for (int i = 0; i < 5; i++) cin >> str;


	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			int data;
			scanf("%x,", &data);
			for (int k = 8 * (j); k <= 8 * (j + 1) - 1; k++) {
				field[i][k] = (data & 1);
				data /= 2;
			}
		}
	}

	cin >> str;

	cout << h << endl;
	cout << quadtree(0, 0, h) << endl;

	return 0;
}

string quadtree(int y, int x, int n) {

	if (n == 0) {
		if (!field[y][x]) return "W";
		return "B";
	}

	n /= 2;

	string ret = quadtree(y, x, n);
	ret += quadtree(y, x + n, n);
	ret += quadtree(y + n, x, n);
	ret += quadtree(y + n, x + n, n);

	if (ret == "WWWW")
		return "W";
	else if (ret == "BBBB")
		return "B";

	return "Q" + ret;
}
