#include <iostream>
#include <vector>
#include <string>
#include <queue>
 
using namespace std;
 
struct point {
    int x, y, v;
    point(int _y, int _x, int _v) : y(_y), x(_x), v(_v) {}
    point() {}
};
 
int n, m;
vector<string> graph;
int alpha();
bool judge(int y, int x, int s);
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
 
int main() {
    cin >> n >> m;
    graph.assign(n, "");
    for (int i = 0; i < n; i++) cin >> graph[i];
    cout << alpha() << endl;
    return 0;
}
 
int alpha() {
    int ret = 1;
    queue<point> q;
    q.push(point(0, 0, 0 | (1 << (graph[0][0] - 'A'))));
    while (!q.empty()) {
        int x = q.front().x, y = q.front().y, v = q.front().v;
        q.pop();
        int temp = 0;
        for (int i = 0; i < 32; i++) ((v >> i) & 1) && temp++;
        ret = (ret > temp ? ret : temp);
        for (int i = 0; i < 4; i++) {
            int nextX = x + dx[i], nextY=y+dy[i];
            if (judge( nextY, nextX, v) ) {
                q.push(point(nextY, nextX, v | (1 << (graph[nextY][nextX] - 'A'))));
            }
        }
    }
    return ret;
}
bool judge(int y, int x,int s) {
    if (y >= n || x >= m || x < 0 || y < 0) return false;
    if (((1 << (graph[y][x] - 'A') & s) != 0)) return false;
    return true;
}
