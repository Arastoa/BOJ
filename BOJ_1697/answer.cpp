#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define SIZE 100001
using namespace std;

int bfs();
vector<int> graph[SIZE];
void setting();
int n, k;

int main() {

	setting();
	cin >> n >> k;
	cout << bfs() << endl;
	return 0;
}

int bfs() {
	vector<bool> visited(SIZE,false);
	int ret = SIZE+3;
	queue<pair<int, int> > q;
	q.push(make_pair(n, 0));

	while (!q.empty()) {
		int here = q.front().first, cnt = q.front().second;
		q.pop();
		visited[here] = true;
		if (cnt > ret) continue;
		if (here == k) {
			ret = min(ret, cnt);
		}
		for (int i = 0; i < graph[here].size(); i++) {
			int there = graph[here][i];
			if (!visited[there]) q.push(make_pair(there, cnt + 1));
		}
	}

	return ret;
}

void setting() {
	graph[0].push_back(1);
	graph[SIZE - 1].push_back(SIZE - 2);
	for (int i = 1; i < SIZE-1; i++) {
		graph[i].push_back(i + 1);
		graph[i].push_back(i - 1);
		if (i * 2 < SIZE) graph[i].push_back(i * 2);
	}
}
