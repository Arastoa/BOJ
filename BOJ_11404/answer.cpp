#include <iostream>
#include <algorithm>
#include <string.h>
#define INF 987654321
#define MAX_V 101
using namespace std;
 
int adj[MAX_V][MAX_V];
int via[MAX_V][MAX_V];
int V;
void floyd() {
    for (int i = 1; i <= V; i++) adj[i][i]=0;
    memset(via, -1, sizeof(via));
    for (int k = 1; k <= V; k++)
        for (int i = 1; i <= V; i++)
            for (int j = 1; j <= V; j++)
                if (adj[i][j] > adj[i][k] + adj[k][j]) {
                    via[i][j] = k;
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
}
 
int main() {
 
    int m; cin >> V >> m;
 
    for (int i = 0; i <= V; i++)
        for (int j = 0; j <= V; j++) adj[i][j] = INF;
 
    for (int i = 0; i < m; i++) {
        int s, e, w;
        cin >> s >> e >> w;
        adj[s][e] = min(w,adj[s][e]);
    }
    floyd();
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) cout << adj[i][j] << ' ';
        cout << endl;
    }
 
    return 0;
}
