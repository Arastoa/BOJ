#include <iostream>
#include <set>

using namespace std;

int schedule(const set<pair<int, int> >& order);

int main(){
	int n;
	set<pair<int, int> > order;

	cin >> n;
	for (int i = 0; i < n; i++){
		int begin, end;
		cin >> begin >> end;
		order.insert(make_pair(end, begin));
	}
	cout << schedule(order) << endl;

	return 0;
}

int schedule(const set<pair<int, int> >& order){
	int selected = 0, earliest=0;
	set<pair<int, int> >::iterator itr = order.begin();

	while (itr != order.end()){
		int meetingBegin = itr->second, meetingEnd = itr->first;
		if (earliest <= meetingBegin){
			earliest = meetingEnd;
			selected++;
		}
		itr++;
	}

	return selected;
}
