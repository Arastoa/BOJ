#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321
 
using namespace std;
 
typedef struct edge {
    int v, c, d;
    edge(int _v, int _c, int _d) : v(_v), c(_c), d(_d) {}
    bool operator< (const edge& rhs) const {
        return d < rhs.d;
    }
    edge() {}
};
 
typedef struct EdgeCompare{
    bool operator()(const edge& lhs, const edge& rhs) const {
        return lhs.d > rhs.d;
    }
};
 
int cache[100][10005];
vector<vector<edge> > graph;
vector<bool> visited;
 
int n, m, k,result;
void dijstra();
 
int main() {
    int t; cin >> t;
 
    while (t--) {
        cin >> n >> m >> k;
        int u, v, c, d;
        result = INF;
        graph.clear();
        graph.assign(n, vector<edge>());
        visited = vector<bool>(n, false);
        memset(cache, -1, sizeof(cache));
 
        for (int i = 0; i < k; i++) {
            cin >> u >> v >> c >> d;
            u--, v--;
 
            graph[u].push_back(edge(v,c,d));
        }
        dijstra();
        if(result==INF)
            cout << "Poor KCM" <<endl;
        else
            cout << result << endl;
    }
 
    return 0;
}
 
void dijstra() {
    priority_queue<edge,vector<edge>, EdgeCompare > q;
    for (int i = 0; i < graph[0].size(); i++) {
        q.push(graph[0][i]);
    }
 
    while (!q.empty()) {
        int v, c, d;
        v = q.top().v, c = q.top().c, d = q.top().d;
        //cout << v << ' ' << c << ' ' << d << endl;
        q.pop();
        if (c > m) continue;
        if (v == n - 1) {
            result = min(result, d);
            continue;
        }
        int &compare = cache[v][c];
        compare = d;
 
        for (int i = 0; i < graph[v].size(); i++) {
            if (cache[v][graph[v][i].c+c] == -1 || d + graph[v][i].d <= cache[v][graph[v][i].c + c]) {
                q.push(edge(graph[v][i].v,graph[v][i].c+c,graph[v][i].d+d));
                cache[v][graph[v][i].c + c] = graph[v][i].d + d;
            }
        }
    }
 
}
