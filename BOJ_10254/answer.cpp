#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <set>
#include <stdio.h>
#pragma warning(disable : 4996)
 
using namespace std;
 
struct point{
    long long x, y;
 
    point(){}
    point(long long _y, long long _x) : y(_y), x(_x){}
};
void make_convex_hull(vector<point>& P, vector<point>& s);
int ccw(point p1, point p2, point p3);
bool cmp(const point &u, const point &v);
long long dist(point p1, point p2);
void pick(const vector<point>& convex);
int n;
point p;
 
int main(){
 
    int t; cin >> t;
    while (t--){
        cin >> n;
        vector<point> points;
 
        for (int i = 0; i < n; i++){
            long long x, y; scanf("%lld %lld", &x, &y);
            points.push_back(point(y, x));
        }
 
        vector<point> convex; make_convex_hull(points, convex);
        pick(convex);
    }
 
    return 0;
}
 
void pick(const vector<point>& convex){
    int t1, t2; t1 = t2 = 0;
    long long maxDist = 0;
 
    for (int i = 0; i < convex.size() / 2 + 1; i++){
        int j = (i + 1) % convex.size();
        while (dist(convex[i], convex[j]) < dist(convex[i], convex[(j + 1) % convex.size()])){
            j = (j + 1) % convex.size();
        }
        long long d = dist(convex[i], convex[j]);
        if (maxDist < d){
            maxDist = d;
            t1 = i, t2 = j;
        }
    }
    cout << convex[t1].x << ' ' << convex[t1].y << ' ' << convex[t2].x << ' ' << convex[t2].y << endl;
}
 
 
int ccw(point p1, point p2, point p3){
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
 
long long dist(point p1, point p2) {
    long long d1 = p1.x - p2.x;
    long long d2 = p1.y - p2.y;
    return d1*d1 + d2*d2;
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
 
void make_convex_hull(vector<point>& P, vector<point>& s){
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
