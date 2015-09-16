#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

vector<string> graph;
int R, C;
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, 1, -1, 0 };
bool judge(int y, int x);
bool bfs(int y, int x);
bool visited[10][10] = { false, };

int main(){

	cin >> R >> C;
	for (int i = 0; i < R; i++){
		string str; cin >> str;
		graph.push_back(str);
	}

	int startY, startX;
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++)
		if (graph[i][j] != 'X'){
			startY = i, startX = j; break;
		}
	}

	cout << bfs(startY, startX) << endl;

	return 0;
}

bool judge(int y, int x){
	if (y >= R || x >= C || x < 0 || y < 0 || graph[y][x]=='X') return false;
	return true;
}
bool bfs(int y, int x){
	queue<pair<int, int> > q;
	q.push(make_pair(y, x));
	visited[y][x] = true;

	while (!q.empty()){
		int hereY = q.front().first, hereX = q.front().second,cnt=0;
		q.pop();
		for (int i = 0; i < 4; i++){
			int nextY = hereY + dy[i], nextX = hereX + dx[i];
			if (judge(nextY,nextX )){
				cnt++;
				if (!visited[nextY][nextX]){
					q.push(make_pair(nextY, nextX));
					visited[nextY][nextX] = true;
				}
			}
		}
		if (cnt <= 1) return true;

	}


	return false;
}
