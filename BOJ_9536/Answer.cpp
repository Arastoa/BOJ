#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

void setData(vector<string>& vt, string animals);
void printVector(const vector<string>& vt);

int main(){

	int n;
	cin >> n;
	

	while (n--){
		getchar();
		vector<string> vt;
		string animals;
		getline(cin, animals);

		setData(vt, animals);

		while (true){
			string growl;
			cin >> growl;
			if (growl == "what")
				break;
			cin >> growl;
			cin >> growl;
			vector<string>::iterator itr = find(vt.begin(), vt.end(), growl);
			while (itr != vt.end()){
				vt.erase(itr);
				itr = find(vt.begin(), vt.end(), growl);
			}
		}
		for (int i = 0; i < 4; i++)
			cin >> animals;
		printVector(vt);
	}


	return 0;
}


void setData(vector<string>& vt, string animals){
	string data = "";
	for (int i = 0; i < animals.size();i++)
	if (animals[i] != ' ')
		data = data+animals[i];
	else{
		vt.push_back(data);
		data = "";
	}
	vt.push_back(data);
}

void printVector(const vector<string>& vt){
	for (int i = 0; i < vt.size(); i++)
		cout << vt[i] << ' ';
	cout << endl;
}
