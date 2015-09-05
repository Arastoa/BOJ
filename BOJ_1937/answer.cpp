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
int n, result = 0;
int visited[501][501];
int crashWall(int y, int x);
vector<vector<int> > field;

int main(){

	cin >> n;
	memset(visited, -1, sizeof(visited));
	field.assign(n, vector<int>());
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			int data; cin >> data;
			field[i].push_back(data);
		}
	}

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			result=max(result,crashWall(i, j));
		}
	}
	cout << result << endl;

	return 0;
}


int crashWall(int y ,int x){
	int& ret = visited[y][x];
	if (ret != -1) return ret;

	ret = 1;

	for (int i = 0; i < 4; i++){
		int nextY = y + dy[i], nextX = x + dx[i];
		if (isRange(nextY, nextX) && field[nextY][nextX] > field[y][x]) ret = max(ret, crashWall(nextY, nextX) + 1);
	}

	return ret;
}

bool isRange(int y, int x){
	if (y >= n || x >= n || y < 0 || x < 0) return false;
	return true;
}
