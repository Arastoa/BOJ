#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define V 10001
#define INF 987654321
using namespace std;
 
vector<pair<int,int> > graph[10001];
int dij(int start, int end);
 
int main(){
    int n, m, start, end, weight; cin >> n >> m;
    n--;
    while (n--){
        cin >> start >> end >> weight;
        graph[start].push_back(make_pair(end, weight));
        graph[end].push_back(make_pair(start, weight));
    }
 
    while (m--){
        cin >> start >> end;
        cout << dij(start, end) << endl;
    }
 
    return 0;
}
 
int dij(int start, int end){
    vector<int> dist(V, INF);
    dist[start] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, start));
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if (dist[here] < cost) continue;
         
        for (int i = 0; i < graph[here].size(); ++i) {
            int there = graph[here][i].first;
            int nextDist = cost + graph[here][i].second;
            if (dist[there] > nextDist) {
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
            }
        }
    }
    return dist[end];
}
