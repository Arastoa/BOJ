#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

int isContact(int& x1, int& y1, int& r1, int& x2, int& y2, int& r2);

int main(){
	int x1, y1, x2, y2, r1, r2;
	int n;
	cin >> n;

	while (n--){
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		cout << isContact(x1, y1, r1, x2, y2, r2) << endl;
	}

	return 0;
}

int isContact(int& x1, int& y1, int& r1, int& x2, int& y2, int& r2){
	if (x1 == x2 && y1 == y2 && r1 == r2)
		return -1;

	double d = sqrt((y2 - y1)*(y2 - y1) + (x2 - x1)*(x2 - x1));
	if (abs(r2 - r1) < d && d < r2 + r1)
		return 2;
	else if (abs(r2 - r1) == d || d == r2 + r1)
		return 1;
	else if (d<abs(r2 - r1) || d>r2 + r1)
		return 0;
}
