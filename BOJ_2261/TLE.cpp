#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <stdio.h>
#pragma warning(disable : 4996)
using namespace std;

struct point{
	long long x, y;
	point(){}
	point(long long _x, long long _y) : x(_x), y(_y){}
};

bool xCompare(const point& lhs, const point& rhs){
	return lhs.x < rhs.x;
}

bool yCompare(const point& lhs, const point& rhs){
	return lhs.y < rhs.y;
}


long long dist(const point& p1, const point& p2){
	return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}

long long brute_force(point* pts, int max_n){
	int i, j;
	long long d, min_d = 20000000000;

	for (i = 0; i < max_n; i++) {
		for (j = i + 1; j < max_n; j++) {
			d = dist(pts[i], pts[j]);
			if (d >= min_d) continue;
			min_d = d;
		}
	}
	return min_d;
}

long long closest(point* sx, int nx, point* sy, int ny){
	int left, right, i;
	long long d, min_d, x0, x1, mid, x;
	point a1, b1;
	point *s_yy;

	if (nx <= 16) return brute_force(sx, nx);

	s_yy = (point*)malloc(sizeof(point)* ny);
	mid = sx[nx / 2].x;

	left = -1; right = ny;
	for (i = 0; i < ny; i++)
	if (sy[i].x < mid) s_yy[++left] = sy[i];
	else                s_yy[--right] = sy[i];

	for (i = ny - 1; right < i; right++, i--) {
		a1 = s_yy[right]; s_yy[right] = s_yy[i]; s_yy[i] = a1;
	}

	min_d = closest(sx, nx / 2, s_yy, left + 1);
	d = closest(sx + nx / 2, nx - nx / 2, s_yy + left + 1, ny - left - 1);

	if (d < min_d) { min_d = d; }
	d = min_d;

	left = -1; right = ny;
	for (i = 0; i < ny; i++) {
		x = sy[i].x - mid;
		if (x <= -d || x >= d) continue;

		if (x < 0) s_yy[++left] = sy[i];
		else       s_yy[--right] = sy[i];
	}

	while (left >= 0) {
		x0 = s_yy[left].y + d;
		while (right < ny && s_yy[right].y > x0) right++;
		if (right >= ny) break;

		x1 = s_yy[left].y - d;
		for (i = right; i < ny && s_yy[i].y > x1; i++)
		if ((x = dist(s_yy[left], s_yy[i])) < min_d) {
			min_d = x;
			d = min_d;
		}
		left--;
	}
	free(s_yy);
	return min_d;
}

int main(){
	int n; cin >> n;
	point* p1, *p2,a,b;
	p1 = new point[n];
	p2 = new point[n];

	for (int i = 0; i < n; i++){
		int x, y; scanf("%d %d", &x, &y);
		p1[i] = point(x, y);
		p2[i] = point(x, y);
	}
	sort(p1, p1 + n, xCompare);
	sort(p2, p2 + n, yCompare);

	cout << closest(p1, n, p2, n) << endl;
	free(p1), free(p2);
	return 0;
}
