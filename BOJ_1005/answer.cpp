#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stdio.h>
#pragma warning(disable : 4996)
 
using namespace std;
 
vector<int> indegree;
vector<int> temp;
vector<bool> visited;
vector<vector<int> > graph;
vector<int> times, footprint;
vector<int> getTimes(int n);
vector<vector<int> > getGraph(int n, int m);
void bfs(int n);
int target, result;
 
int main(){
 
    int t; cin >> t;
 
    while (t--){
        vector<int> startingPoint;
        int n, m; cin >> n >> m; result = 0;
        indegree = vector<int>(n, 0);
        times = getTimes(n);
        graph = getGraph(n, m);
        cin >> target; target--;
 
        if (indegree[target] == 0){
            cout << times[target] << endl;
            continue;
        }
         
 
        for (int i = 0; i < indegree.size(); i++)
        if (indegree[i] == 0) startingPoint.push_back(i);
 
 
        for (int i = 0; i < startingPoint.size(); i++){
            temp = vector<int>(indegree);
            footprint = vector<int>(times);
            bfs(startingPoint[i]);
        }
 
        cout << result << endl;
    }
 
    return 0;
}
 
void bfs(int n){
 
    queue<pair<int, int> > q;
 
    q.push(make_pair(n, times[n]));
 
    while (!q.empty()){
        pair<int, int> p = q.front();
        q.pop();
         
        if (p.first == target){ 
            result = max(result, p.second); 
            continue; 
        }
 
        for (int i = 0; i < graph[p.first].size(); i++){
            temp[graph[p.first][i]]--;
            footprint[graph[p.first][i]] = max(p.second + times[graph[p.first][i]], footprint[graph[p.first][i]]);
            if (temp[graph[p.first][i]]==0)
                q.push(make_pair(graph[p.first][i], footprint[graph[p.first][i]]));
        }
    }
}
 
vector<vector<int> > getGraph(int n, int m){
    vector<vector<int> > graph(n);
    while (m--){
        int start, end; scanf("%d %d", &start, &end); start--; end--;
        graph[start].push_back(end);
        indegree[end]++;
    }
    return graph;
}
 
 
vector<int> getTimes(int n){
    vector<int> times(n);
    for (int i = 0; i < n; i++){
        cin >> times[i];
    }
    return times;
}
