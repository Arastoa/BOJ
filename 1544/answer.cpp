#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
	string str;
	string temp;
	set<string> s;

	int n; cin >> n;

	cin >> str;
	s.insert(str);
	for (int i = 1; i < n; i++)
	{
		cin >> str;
		temp = str;
		temp.append(temp);
		bool isEqual = false;
		for (set<string>::iterator itr = s.begin(); itr != s.end(); itr++)
		{
			if (temp.find(*itr) != -1 && temp.size()/2 == itr->size())
			{
				isEqual = true;
				break;
			}
		}
		if (!isEqual)
			s.insert(str);

	}
	cout << s.size()<<endl;

	return 0;
}
