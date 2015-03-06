#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(){

	int num,dir,length,xMaxdir,xMax=-1,xPos,yPos,yMax=-1,yMaxdir,ret;
	vector<pair<int, int> > field;
	cin >> num;

	//값 넣고 최대값 정하기
	for (int i = 0; i < 6; i++){
		cin >> dir >> length;
		field.push_back(make_pair(dir, length));
		switch (dir)
		{
		case 1: case 2:
			if (length>xMax){
				xMax = length;
				xMaxdir = dir;
				xPos = i;
			}
			break;
		case 3: case 4:
			if (length>yMax){
				yMax = length;
				yMaxdir = dir;
				yPos = i;
			}
		}
	}
	

	ret = xMax*yMax;
	if (xPos == 0 && yPos == 1 || yPos == 0 && xPos == 1)
		ret -= (field[3].second * field[4].second);
	else if (xPos == 1 && yPos == 2 || yPos == 1 && xPos == 2)
		ret -= (field[4].second * field[5].second);
	else if (xPos == 2 && yPos == 3 || yPos == 2 && xPos == 3)
		ret -= (field[0].second * field[5].second);
	else if (xPos == 3 && yPos == 4 || yPos == 3 && xPos == 4)
		ret -= (field[0].second * field[1].second);
	else if (xPos == 4 && yPos == 5 || yPos == 4 && xPos == 5)
		ret -= (field[1].second * field[2].second);
	else if (xPos == 0 && yPos == 5 || yPos == 0 && xPos == 5)
		ret -= (field[2].second * field[3].second);
	

	cout << ret*num << endl;
	return 0;
}
