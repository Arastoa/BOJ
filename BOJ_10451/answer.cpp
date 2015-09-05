#include <iostream>
#include <queue>
#include <vector>
#include <string.h>

using namespace std;

vector<vector<int> > graph;
void dfs(int start);
bool visited[1001];


int main(){

	int t; cin >> t;
	while (t--){
		int n,cycles=0; cin >> n;
		graph = vector<vector<int> >(n + 1, vector<int>());
		memset(visited, false, sizeof(visited));

		for (int i = 1; i <= n; i++){
			int permutation; cin >> permutation;
			graph[i].push_back(permutation);
		}

		for (int i = 1; i <= n; i++){
			if (!visited[i]){
				dfs(i); cycles++;
			}
		}
		cout << cycles << endl;
	}

	return 0;
}

void dfs(int start){
	queue<int> q;
	q.push(start);
	
	while (!q.empty()){
		int here = q.front();
		visited[here] = true;
		q.pop();
		for (int there = 0; there < graph[here].size(); there++){
			if (!visited[graph[here][there]]) q.push(graph[here][there]);
		}
	}
}
