#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct tri{
	int z, y, x;
	tri(int _z, int _y, int _x) : z(_z), y(_y), x(_x){}
};

void printVector(const vector <vector<vector<int> > >& vt);
void ripeTomato(vector <vector<vector<int> > >& vt, int day, tri& direcotion);
bool judgeDirection(tri& p);
bool judgePush(const vector <vector<vector<int> > >& vt, tri& p);
int calDay(const vector <vector<vector<int> > >& vt);
int n, m,k;
int dx[4] = { 0, -1, 1, 0 }, dy[4] = { -1, 0, 0, 1 }, dz[2] = { -1, 1 };



int main(){

	cin >> m >> n>>k;
	vector <vector<vector<int> > > vt(k);
	for (int i = 0; i < k; i++)
		vt[i].assign(n, vector<int>(m));
	queue<tri> q;

	for (int t = 0; t < k; t++)
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				cin >> vt[t][i][j];
				if (vt[t][i][j] == 1) q.push(tri(t,i,j));
			}
		}

	while (!q.empty()){
		tri p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++){
			tri temp = tri(p.z,p.y+dy[i],p.x+dx[i]);
			if (judgePush(vt, temp)){
				q.push(temp);
				ripeTomato(vt, vt[p.z][p.y][p.x], temp);
				//printVector(vt);
			}
		}
		for (int i = 0; i < 2; i++){
			tri temp = tri(p.z+dz[i], p.y, p.x);
			if (judgePush(vt, temp)){
				q.push(temp);
				ripeTomato(vt, vt[p.z][p.y][p.x], temp);
				//printVector(vt);
			}
		}
	}

	//printVector(vt);

	cout << calDay(vt) << endl;

	return 0;
}

int calDay(const vector<vector<vector<int> > >& vt){
	int max = 1;
	for (int k = 0; k < vt.size(); k++)
		for (int i = 0; i < vt[k].size(); i++){
			for (int j = 0; j < vt[k][i].size(); j++){
				if (vt[k][i][j] == 0){
					return -1;
				}
				else if (max < vt[k][i][j]) max = vt[k][i][j];
			}
		}
	return max - 1;
}

void ripeTomato(vector<vector<vector<int> > >& vt, int day, tri& direction){
	if (!judgeDirection(direction)) return;
	if (vt[direction.z][direction.y][direction.x] != 0) return;
	vt[direction.z][direction.y][direction.x] = day + 1;
}

bool judgeDirection(tri& p){
	if (p.y >= n || p.x >= m || p.y < 0 || p.x < 0 || p.z >=k || p.z<0) return false;
	return true;
}

bool judgePush(const vector<vector<vector<int> > >& vt, tri& direction){
	if (!judgeDirection(direction)) return false;
	if (vt[direction.z][direction.y][direction.x] == 0) return true;
	return false;
}
