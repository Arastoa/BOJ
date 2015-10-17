#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <stdio.h>
#pragma warning(disable : 4996)
using namespace std;

vector<pair<int, int> > monoton(map<int, vector<int> >& m);

int main() {
	int t; cin >> t;
	while (t--) {
		int index, n, x, y; cin >> n;
		map<int, vector<int> >m;
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &x, &y);
			m[x].push_back(y);
		}
		vector<pair<int, int> > mono = monoton(m);
		/*
		for(int i=0 ; i< mono.size() ; i++)
		cout<<mono[i].first<<' '<<mono[i].second<<endl;
		*/
		cin >> n;
		for (int i = 0; i < n; i++) {
			scanf("%d", &index); index--;
			printf("%d %d\n", mono[index].first, mono[index].second);
		}
		
	}

	return 0;
}
vector<pair<int, int> > monoton(map<int, vector<int> >& m) {
	vector<pair <int, int> > ret; bool cont = false;
	sort(m.begin()->second.begin(), m.begin()->second.end());
	if(m.begin()->second.front()==0)
		for (int i = 0; i < m.begin()->second.size(); i++) ret.push_back(make_pair(m.begin()->first, m.begin()->second[i]));
	else
		for (int i = m.begin()->second.size()-1; i >=0 ; i--) ret.push_back(make_pair(m.begin()->first, m.begin()->second[i]));

	if (m.begin()->second.back() > 0) cont = true;

	map<int, vector<int> >::iterator here, front;
	here = front = m.begin(); here++;
	while (here != m.end()) {
		sort(here->second.begin(), here->second.end());

		if (front->second.size() == 1) {
			if (front->second.front() == here->second.front()) cont = true;
			else cont = false;
		}
		else {
			if (front->second.back() == here->second.front()) cont = true;
			else if (front->second.front() == here->second.front() || front->second.back() == here->second.back()) cont = !cont;
			else if(front->second.front() == here->second.back()) cont = false;
		}
		if (cont)
			for (int i = 0; i < here->second.size(); i++) ret.push_back(make_pair(here->first, here->second[i]));
		
		else 
			for (int i = here->second.size() - 1; i >= 0; i--) ret.push_back(make_pair(here->first, here->second[i]));
		
		
		here++; front++;
	}

	return ret;
}
