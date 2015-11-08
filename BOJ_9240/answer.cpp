#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <vector>
 
using namespace std;
 
struct point {
    long long x, y;
    point() {}
    point(long long _x, long long _y) : x(_x), y(_y) {}
};
point p;
int n;
long long dist(point p1, point p2) {
    long long d1 = p1.x - p2.x;
    long long d2 = p1.y - p2.y;
    return d1*d1 + d2*d2;
}
int ccw(point p1, point p2, point p3) {
    long long temp = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
    if (temp > 0) {
        return 1;
    }
    else if (temp < 0) {
        return -1;
    }
    else {
        return 0;
    }
}
 
bool cmp(const point &u, const point &v) {
    int temp = ccw(p, u, v);
    if (temp == 0) {
        return dist(p, u) <= dist(p, v);
    }
    else {
        return temp == 1;
    }
}
 
void make_convex_hull(vector<point>& P, vector<point>& s) {
    p = P[0];
    for (int i = 1; i<n; i++) {
        if (P[i].y < p.y || (P[i].y == p.y && P[i].x < p.x)) {
            p = P[i];
        }
    }
 
    sort(P.begin(), P.end(), cmp);
    for (int i = 0; i<n; i++) {
        while (s.size() >= 2 && ccw(s[s.size() - 2], s[s.size() - 1], P[i]) <= 0) {
            s.pop_back();
        }
        s.push_back(P[i]);
    }
}
 
long long calDist(const vector<point>& s) {
    long long ret = 0;
 
    for (int i = 0; i < s.size()/2+1; i++) {
        int j = (i + 1) % s.size();
        long long d = dist(s[i], s[j]);
        while (d < dist(s[i], s[(j+1)%s.size()])) {
            j=(j+1)%s.size(); 
            d = dist(s[i], s[j]);
        }
        ret = max(ret, d);
    }
     
    return ret;
}
 
int main() {
    cin >> n;
    vector<point> p, s;
    for (int i = 0; i < n; i++) {
        long long x, y; cin >> x >> y;
        p.push_back(point(x, y));
    }
    make_convex_hull(p, s);
    printf("%.7lf\n", sqrt(calDist(s)));
    return 0;
}
