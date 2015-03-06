#include <iostream>

using namespace std;

void printCnt(const int & n, const int & m);

int main(){

	int n, m;
	cin >> n >> m;

	printCnt(n, m);
	
	return 0;
}

void printCnt(const int & n, const int & m){
	if (n - m <= 0)
		cout << n * 2 - 2 << endl;
	else
		cout << m * 2 - 1 << endl;

}
