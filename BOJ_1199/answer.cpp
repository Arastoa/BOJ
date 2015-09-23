#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > adj;
vector<vector<int> > temp;
void getEulerCircuit(int here, vector<int>& circuit);

int main(){

	int n; cin >> n;
	adj.assign(n, vector<int>());
	vector<int> circuit;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			int data; cin >> data;
			adj[i].push_back(data);
		}
	}
	int here = 0;
	while (here<n){
		circuit.clear();
		temp = adj;
		getEulerCircuit(here++, circuit);
		if (circuit.size() >= n ) break;
	}

	if (circuit[0]==circuit[circuit.size()-1])
	for (int i = 0; i < circuit.size(); i++)
		cout << circuit[i] + 1 << ' ';
	else
		cout << -1 << endl;

	return 0;
}

void getEulerCircuit(int here, vector<int>& circuit){

	for (int there = 0; there < temp[here].size(); there++){
		while (temp[here][there] > 0){
			temp[here][there]--;
			temp[there][here]--;

			getEulerCircuit(there, circuit);
		}
	}
	circuit.push_back(here);
}
