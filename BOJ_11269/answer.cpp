#include <iostream>
#include <string>

using namespace std;

int main() {

	string str; cin >> str;
	string p = "PER"; int j = 0,result=0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] != p[j]) result++;
		j = (j + 1) % 3;
	} 
	cout << result << endl;

	return 0;
}
