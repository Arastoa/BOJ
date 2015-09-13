#include <iostream>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

struct point{
	long long x, y;
	point(long long _x, long long _y) : x(_x), y(_y){}
};

long double area(const vector<point>& p);

int main(){
	vector<point> p;
	int n; cin >> n;

	for (int i = 0; i < n; i++){
		long long x, y;
		cin >> x >> y;
		p.push_back(point(x, y));
	}

	printf("%.1Lf\n", area(p));

	return 0;
}
//볼록 오목 상관없이 가능
long double area(const vector<point>& p){
	long double ret = 0;
	for (int i = 0; i < p.size(); i++){
		int j = (i + 1) % p.size();
		ret += (p[i].x + p[j].x)*(p[i].y - p[j].y);
	}
	
	return fabs(ret) / 2.0;
}
