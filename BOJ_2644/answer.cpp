#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct NaiveDisjointSet{
	vector<int> parent;
	vector<int> path1, path2;
	NaiveDisjointSet(int n) : parent(n+1){
		for (int i = 0; i < parent.size(); i++)
			parent[i] = i;
	}

	int find(int u) const {
		if (u == parent[u]) return u;
		return find(parent[u]);
	}

	int path1Find(int u){
		
		if (u == parent[u]) return u;
		path1.push_back(parent[u]);
		return path1Find(parent[u]);
	}

	int path2Find(int u){
		
		if (u == parent[u]) return u;
		path2.push_back(parent[u]);
		return path2Find(parent[u]);
	}

	void merge(int u, int v){
		int tu = find(u), tv = find(v);
		if (tu == tv) return;
		
		parent[u] = v;
	}
};

int main(){

	int n; cin >> n;
	NaiveDisjointSet naive(n);
	int t1, t2; cin >> t1 >> t2;
	int m; cin >> m;
	
	while (m--){
		int x, y; cin >> x >> y;
		naive.merge(y,x);
	}

	naive.path1.push_back(t1); naive.path2.push_back(t2);

	if (naive.path1Find(t1) != naive.path2Find(t2)){
		cout << -1 << endl;
		return 0;
	}

	int result=0;

	for (int i = 0; i < naive.path1.size(); i++){
		vector<int>::iterator itr = find(naive.path2.begin(), naive.path2.end(), naive.path1[i]);
		if (itr != naive.path2.end()){
			if (naive.path2.size() == 1){
				result = naive.path1.size()-1;
			}
			else{
				result = i;
				result += itr - naive.path2.begin();
				break;
			}
		}
	}

	cout << result << endl;

	return 0;
}
