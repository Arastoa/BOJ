#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(){
	int n, m;
	string str;
	set<string> nList, list;
	cin >> n >> m;

	for (int i = 0; i < n; i++){
		cin >> str;
		nList.insert(str);
	}

	for (int i = 0; i < m; i++){
		cin >> str;
		if (nList.find(str) != nList.end())
			list.insert(str);
	}

	cout << list.size() << endl;
	for (set<string>::iterator itr = list.begin(); itr != list.end(); itr++)
		cout << *itr << endl;

	return 0;
}
