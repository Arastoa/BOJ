#include <iostream>
#include <queue>

using namespace std;

bool adj[100][100] = { 0, };
bool visited[100][100] = { 0, };
int n;
void bfs();

int main(){

	cin >> n;

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)  cin >> adj[i][j];
	}
	bfs();
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++) cout << visited[i][j] << ' ';
		cout << endl;
	}

	return 0;
}

void bfs(){
	queue<int> q;
	for (int i = 0; i < n; i++){

		for (int j = 0; j < n; j++)
		if (adj[i][j] && !visited[i][j]){
			q.push(j);
			visited[i][j] = true;
		}

		while (!q.empty()){
			int here = q.front();
			q.pop();
			for (int j = 0; j < n; j++)
			if (adj[here][j] && !visited[i][j]){
				q.push(j);
				visited[i][j] = true;
			}
		}
	}
}
