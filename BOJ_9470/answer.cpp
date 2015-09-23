#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <stdio.h>
#pragma warning(disable : 4996)

using namespace std;

vector<int> indegree, startingPoint;
vector<vector<int> > graph, cache;
vector<int> times;
vector<vector<int> > getGraph(int m);
void bfs(int n);

int main(){

	int t; cin >> t;

	while (t--){
		startingPoint.clear();
		int k, n, m; cin >> k >> n >> m; n--;
		indegree = vector<int>(1001, 0);
		times = vector<int>(1001, 0);
		cache=vector<vector<int> >(1001, vector<int>());
		graph = getGraph(m);

		for (int i = 0; i <= n; i++){
			if (indegree[i] == 0){
				startingPoint.push_back(i);
				times[i] = 1;
			}
		}

		for (int i = 0; i < startingPoint.size(); i++){
			bfs(startingPoint[i]);
		}
		cout << k << ' ' << times[n] << endl;
	}
	return 0;
}

void bfs(int n){
	indegree[n]--;
	for (int i = 0; i < graph[n].size(); i++){
		indegree[graph[n][i]]--;
		cache[graph[n][i]].push_back(times[n]);
		if (indegree[graph[n][i]] == 0){
			sort(cache[graph[n][i]].begin(), cache[graph[n][i]].end(), greater<int>());
			if (cache[graph[n][i]].size() == 1) times[graph[n][i]] = cache[graph[n][i]][0];
			else {
				if (cache[graph[n][i]][0] == cache[graph[n][i]][1]) times[graph[n][i]] = cache[graph[n][i]][0]+1;
				else times[graph[n][i]] = cache[graph[n][i]][0];
			}
			startingPoint.push_back(graph[n][i]);
		}
	}
}

vector<vector<int> > getGraph(int m){
	vector<vector<int> > graph(1001);
	while (m--){
		int start, end; scanf("%d %d", &start, &end); start--; end--;
		graph[start].push_back(end);
		indegree[end]++;
	}
	return graph;
}
