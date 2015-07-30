#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > graph;
int bfs(int start);
void setting(int n,int m);
int found[501] = { 0, };

int main(){

	int n, m; cin >> n >> m;
	setting(n, m);
	vector<int> vt(n, 0);
	for (int i = 0; i < n; i++)
		vt[i] = bfs(i);

	for (int i = 0; i < n; i++)
		cout << vt[i] - found[i] << endl;

	return 0;
}

int bfs(int start){
	int ret = 0;
	bool visited[101] = { false, };
	queue<int> q;
	visited[start] = true;
	q.push(start);

	while (!q.empty()){
		int here = q.front();
		q.pop();
		for (int i = 0; i < graph[here].size(); i++){
			if (!visited[graph[here][i]]){
				visited[graph[here][i]] = true;
				q.push(graph[here][i]);
				found[graph[here][i]]++;
			}
		}
	}

	for (int i = 0; i < graph.size(); i++)
	if (!visited[i]) ret++;

	return ret;
}

void setting(int n, int m){
	graph.assign(n, vector<int>());
	while (m--){
		int start, end; cin >> start >> end;
		graph[--start].push_back(--end);
	}

}
