#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<string> field;
vector<string> temp;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int normal();
bool judge(int y, int x);

int odd();
int n;

int main(){
	cin >> n;

	for(int i=0 ; i< n ; i++){
		string str; cin >> str;
		field.push_back(str);
	}
	cout << normal() << ' ' << odd() << endl;

	return 0;
}

int normal(){
	int ret = 0;
	temp = vector<string>( field);

	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (temp[i][j] != '.'){
				ret++;
				char c = temp[i][j];
				temp[i][j]='.';
				queue<pair<int, int> > q;
				q.push(make_pair(i, j));
				while (!q.empty()){
					int y = q.front().first, x = q.front().second;
					
					q.pop();
					for (int k = 0; k < 4; k++)
					if (judge(y + dy[k], x + dx[k]) && c == temp[y + dy[k]][x + dx[k]]) {
						q.push(make_pair(y + dy[k], x + dx[k]));
						temp[y + dy[k]][x + dx[k]] = '.';
					}
				}
			}
		}
	}

	return ret;
}
bool judge(int y, int x){
	if (y < 0 || x < 0 || y >= n || x >= n) return false;
	return true;
}

int odd(){
	int ret = 0;
	temp = field;

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (temp[i][j] != '.'){
				ret++;
				char c = temp[i][j];
				queue<pair<int, int> > q;
				q.push(make_pair(i, j));
				while (!q.empty()){
					int y = q.front().first, x = q.front().second;
					temp[y][x] = '.';
					q.pop();
					for (int k = 0; k < 4; k++)
					if (judge(y + dy[k], x + dx[k])) {
						switch (c)
						{
						case 'R': case 'G':
							if (temp[y + dy[k]][x + dx[k]] == 'R' || temp[y + dy[k]][x + dx[k]] == 'G'){
								q.push(make_pair(y + dy[k], x + dx[k]));
								temp[y + dy[k]][x + dx[k]] = '.';
							}
							break;
						case 'B':
							if (c == temp[y + dy[k]][x + dx[k]]) {
								q.push(make_pair(y + dy[k], x + dx[k]));
								temp[y + dy[k]][x + dx[k]] = '.';
							}
							break;
						}
					}
				}
			}
		}
	}

	return ret;
}
