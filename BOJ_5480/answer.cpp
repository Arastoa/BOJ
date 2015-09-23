#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

class ship{
public :
	int x,x1, y,y1, weight;

	ship(int _x, int _y, int _x1,int _y1, int _weight) {
		x = _x; y = _y; weight = _weight;
		x1 = _x1; y1 = _y1;
	}
};

int maxShip(list<ship>& ships, const int& po, const int& angle,const int& grid);
void swap(int& a, int& b);

int main(){
	int n;
	cin >> n;
	while (n--){
		list<ship> ships;
		int grid, k, r;
		cin >> grid >> k >> r;

		for (int i = 0; i < k; i++){
			int x, y, x1, y1, weight;
			cin >> x >> y >> x1 >> y1 >> weight;
			if (x>x1)
				swap(x, x1);
			if (y > y1)
				swap(y, y1);
			ships.push_back(ship(x, y, x1, y1, weight));
		}

		for (int i = 0; i < r; i++){
			int po, angle;
			cin >> po >> angle;
			cout << maxShip(ships, po, angle, grid) << endl;
		}
	}

	return 0;
}

void swap(int& a, int& b){
	int t = a;
	a = b;
	b = t;
}

int maxShip(list<ship>& ships, const int& po, const int& angle, const int& grid){
	int ret=0;
	list<ship>::iterator itr = ships.begin();

	if (!angle){
        while(itr!=ships.end()){
			if (itr == ships.end())
				break;
            if (itr->y <= po && po <= itr->y1){
                ret = max(ret, itr->weight);
                itr=ships.erase(itr);

				continue;
				
            }
			
			itr++;
        }
    }
    else{
		while (itr != ships.end()){
			if (itr == ships.end())
				break;
			if (itr->x <= po && po <= itr->x1){
				ret = max(ret, itr->weight);
				itr = ships.erase(itr);

				continue;

			}

			itr++;
		}
    }


	return ret;
}
