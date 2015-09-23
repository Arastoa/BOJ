#include <iostream>
#include <string.h>

using namespace std;

long long cache[31][31][61];
long long  medicine(int full, int half, int day);
int n;

int main(){

	while (1){
		cin >> n;
		if (n == 0) break;
		memset(cache, -1, sizeof(cache));
		cout << medicine(n, 0, 0) << endl;
	}

	return 0;
}

long long medicine(int full, int half, int day){
	if (n*2 == day){
		return 1;
	}

	long long& ret = cache[full][half][day];
	if (ret != -1) return ret;

	ret = 0;
	if (full > 0) ret += medicine(full - 1, half + 1, day + 1);
	if (half > 0) ret += medicine(full, half - 1, day + 1);

	return ret;
}
