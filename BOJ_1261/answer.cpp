#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
#include <string>
#include <vector>
#define INF 987654321
using namespace std;

int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, 1, -1, 0 };
bool isRange(int y, int x);
int n, m, result = 987654321;
int visited[100][100];
void crashWall();
vector<string> field;

typedef struct p{
	int y, x, w;
	p(int _y, int _x, int _w) : y(_y), x(_x), w(_w){}
	bool operator<(const p& rhs) const{
		return w > rhs.w;
	}
}p;

int main(){

	cin >> m >> n;
	for (int i = 0; i < n; i++){
		string str; cin >> str;
		field.push_back(str);
	}

	for (int i = 0; i < 100; i++){
		for (int j = 0; j < 100; j++) visited[i][j] = INF;
	}

	crashWall();
	cout << result << endl;

	return 0;
}


void crashWall(){
	priority_queue<p> q;
	q.push(p(0, 0, 0));
	visited[0][0] = 0;

	while (!q.empty()){
		int y, x, w;
		y = q.top().y, x = q.top().x, w = q.top().w;

		q.pop();

		if (y == n - 1 && x == m - 1){
			result = min(result, w);
			continue;
		}

		for (int i = 0; i < 4; i++){
			int nextY = y + dy[i], nextX = x + dx[i];
			if (isRange(nextY, nextX) && (visited[nextY][nextX] == INF || w < visited[nextY][nextX])){
				if (field[nextY][nextX] == '1') {
					q.push(p(nextY, nextX, w + 1)); 
					visited[nextY][nextX] = w + 1;
				}
				else{
					q.push(p(nextY, nextX, w));
					visited[nextY][nextX] = w;
				}
			}

		}
	}
}

bool isRange(int y, int x){
	if (y >= n || x >= m || y < 0 || x < 0) return false;
	return true;
}
