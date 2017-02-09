#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <math.h>
#include <string>

using namespace std;

int main() {
	while (true)
	{
		string str; cin >> str;

		if (str == "*")break;

		int length = str.size();
		int n = length - 2;
		char dStr[3];
		bool isSurprising = true;;

		for (int i = 0; i < n && isSurprising; i++)
		{
			map<string, bool> m;
			for (int j = 0; (j + i + 1) < length; j++)
			{
				dStr[0] = str[j];
				dStr[1] = str[i + j + 1];
				dStr[2] = NULL;
				string temp = string(dStr);
				if (m.find(temp) == m.end())
					m[temp] = true;
				else
				{
					isSurprising = false;
					break;
				}

			}
		}

		cout << str << " is " << (isSurprising ?  "" : "NOT ") << "surprising." << endl;

	}


	return 0;
}
