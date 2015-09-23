#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

map<int, int> coords;
bool isDominated(int x, int y);
void removeDominated(int x, int y);
int registered(int x, int y);
struct point {
	int x, y;
	point() {}
	point(int _x, int _y) : x(-_x), y(-_y) {}
	bool operator<(const point& rhs) const {
		return (x + y) < (rhs.x + rhs.y);
	}
};

int main() {
	int t; cin >> t;
	while (t--) {
		coords.clear();
		int n,result=0; cin >> n;
		
		while (n--) {
			int x, y; cin >> x >> y;
			result = max(result, registered(-x, -y));
		}
		cout << coords.size() << endl;
	}

	return 0;
}

bool isDominated(int x, int y) {
	map<int, int>::iterator itr = coords.lower_bound(x);
	if (itr == coords.end()) return false;
	return y < itr->second;
}
void removeDominated(int x, int y) {
	map<int, int>::iterator itr = coords.lower_bound(x);
	if (itr == coords.begin()) return;
	itr--;
	while (true) {
		if (itr->second > y) break;
		if (itr == coords.begin()) {
			coords.erase(itr);
			break;
		}
		else {
			map<int, int>::iterator jt = itr;
			jt--;
			coords.erase(itr);
			itr = jt;
		}
	}
}
int registered(int x, int y) {
	if (isDominated(x, y)) return coords.size();
	removeDominated(x, y);
	coords[x] = y;
	return coords.size();
}
