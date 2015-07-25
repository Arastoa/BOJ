#include <iostream>

using namespace std;

int henry(int &a, int& b, int& ret);
int gcd(int a, int b);

int main(void) {

	int a, b;
	int n,result=0;
	int ret = 2;
	
	cin >> n;

	for (int i = 0; i < n; i++){
		cin >> a >> b;
		while(a != 1){
			result = henry(a, b,ret);
		}
		cout << b << endl;
		ret = 0;
	}

	return 0;
}

int henry(int &a, int& b, int& ret){

	while (true){
		if ((double)a / (double)b >= 1.0 / (double)ret)
			break;
		ret++;
	}
	a = a*ret - b;
	b = b*ret;
	
	int div = gcd(a, b);
	a /= div;
	b /= div;

	return ret;
}

int gcd(int a, int b){
	if (b == 0) return a;

	return gcd(b, a%b);
}
