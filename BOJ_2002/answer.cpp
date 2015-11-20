#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <functional>
#include <set>

using namespace std;

int main(){
	vector<string> start, end;
	set<string> remove; string str;
	int n,result=0; cin >> n;

	for (int i = 0; i < n; i++){
		cin >> str; start.push_back(str);
	}
	for (int i = 0; i < n; i++){
		cin >> str; end.push_back(str);
	}

	while (start.size() != 0){
		remove.insert(*start.begin());

		while (end.size()!=0 && start.front() != end.front()){
			remove.insert(end.front());
			end.erase(end.begin());
			result++;
		}

		if (!end.empty()) end.erase(end.begin());

		while (start.size()!=0 && remove.find(*start.begin()) != remove.end())
			start.erase(start.begin());
	}

	cout << result << endl;


	return 0;
}
